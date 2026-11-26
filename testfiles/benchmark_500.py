#!/usr/bin/env python3
"""Run 1,000 random 500-element tests against the Push_swap stress harness.

Usage:
    python3 benchmark_500.py
    python3 benchmark_500.py ./stress

The script records operation counts only. It does not save test inputs.
"""

import random
import re
import statistics
import subprocess
import sys
from pathlib import Path

RUNS = 1000
ELEMENT_COUNT = 500
THRESHOLD = 5500
SEED = 43
DEFAULT_EXECUTABLE = "./a.out"
REPORT_FILE = Path("turk_500_1000_summary.txt")

OPERATIONS = {
    "pa", "pb", "sa", "sb", "ss",
    "ra", "rb", "rr", "rra", "rrb", "rrr",
}
REPORTED_COUNT_RE = re.compile(r"Operations:\s*(\d+)")
RESULT_RE = re.compile(r"Result:\s*(OK|KO)")


def run_one(executable: str, values: list[int]) -> tuple[int, int | None, str | None]:
    """Return (printed operation count, reported count, error)."""
    try:
        result = subprocess.run(
            [executable, *(str(value) for value in values)],
            capture_output=True,
            text=True,
            check=False,
        )
    except OSError as exc:
        return 0, None, f"could not execute {executable}: {exc}"

    printed_count = sum(
        line.strip() in OPERATIONS
        for line in result.stdout.splitlines()
    )

    reported_match = REPORTED_COUNT_RE.search(result.stderr)
    result_match = RESULT_RE.search(result.stderr)

    if reported_match is None:
        detail = result.stderr.strip() or "missing 'Operations:' report"
        return printed_count, None, detail

    reported_count = int(reported_match.group(1))

    if result.returncode != 0:
        detail = result.stderr.strip() or f"exit status {result.returncode}"
        return printed_count, reported_count, detail

    if result_match is not None and result_match.group(1) != "OK":
        return printed_count, reported_count, "harness reported KO"

    if printed_count != reported_count:
        return (
            printed_count,
            reported_count,
            f"printed/reported mismatch ({printed_count}/{reported_count})",
        )

    return printed_count, reported_count, None


def main() -> int:
    executable = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_EXECUTABLE
    if len(sys.argv) > 2:
        print(f"Usage: {Path(sys.argv[0]).name} [executable]", file=sys.stderr)
        return 2

    rng = random.Random(SEED)
    base_values = list(range(-250, 0)) + list(range(1, 251))

    results: list[tuple[int, int]] = []
    above_threshold: list[tuple[int, int]] = []
    failures: list[tuple[int, int, int | None, str]] = []

    print(
        f"Running {RUNS} tests with {ELEMENT_COUNT} elements "
        f"using {executable} (seed {SEED})...",
        flush=True,
    )

    for run_number in range(1, RUNS + 1):
        values = base_values.copy()
        rng.shuffle(values)

        printed_count, reported_count, error = run_one(executable, values)
        results.append((run_number, printed_count))

        if printed_count > THRESHOLD:
            # Deliberately store only the run number and operation count.
            above_threshold.append((run_number, printed_count))

        if error is not None:
            failures.append(
                (run_number, printed_count, reported_count, error)
            )

        if run_number % 100 == 0:
            print(f"Completed {run_number}/{RUNS}", flush=True)

    counts = [count for _, count in results]
    ordered = sorted(results, key=lambda item: item[1])

    lines = [
        "Turk Sort benchmark — 500 elements",
        f"Runs requested: {RUNS}",
        f"Successful runs: {RUNS - len(failures)}",
        f"Random seed: {SEED}",
        f"Average printed operations: {statistics.mean(counts):.2f}",
        f"Median printed operations: {statistics.median(counts):.2f}",
        f"Lowest printed operations: {ordered[0][1]}",
        f"Highest printed operations: {ordered[-1][1]}",
        f"Threshold: more than {THRESHOLD} operations",
        f"Runs above threshold: {len(above_threshold)}",
        "",
        "Five highest operation counts (worst):",
    ]

    for run_number, count in reversed(ordered[-5:]):
        lines.append(f"  Run {run_number}: {count} operations")

    lines.extend(["", "Five lowest operation counts (best):"])
    for run_number, count in ordered[:5]:
        lines.append(f"  Run {run_number}: {count} operations")

    lines.extend([
        "",
        f"Every run above {THRESHOLD} operations "
        "(run number and operation count only):",
    ])
    if above_threshold:
        for run_number, count in above_threshold:
            lines.append(f"  Run {run_number}: {count} operations")
    else:
        lines.append("  None")

    lines.extend([
        "",
        "Validation failures (sorting failures, count mismatches, "
        "or execution errors):",
    ])
    if failures:
        for run_number, printed, reported, detail in failures:
            reported_text = (
                str(reported) if reported is not None else "unavailable"
            )
            lines.append(
                f"  Run {run_number}: printed={printed}, "
                f"reported={reported_text}; {detail}"
            )
    else:
        lines.append("  None")

    report = "\n".join(lines) + "\n"
    REPORT_FILE.write_text(report, encoding="utf-8")
    print()
    print(report, end="")
    print(f"Report saved to: {REPORT_FILE.resolve()}")

    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
