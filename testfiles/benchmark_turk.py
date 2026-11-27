#!/usr/bin/env python3
"""Run reproducible random benchmarks against a Push_swap test harness.

Expected harness contract:
- executable accepts the integer values as command-line arguments;
- operation instructions are printed to stdout, one per line;
- stderr contains lines like: Result: OK and Operations: 1234.

The script counts the actual operation lines on stdout as the primary metric,
and also records the harness-reported count so discrepancies are visible.
"""

import csv
import random
import re
import subprocess
from pathlib import Path
from statistics import mean, median

EXECUTABLE = "./turk_test"
RUNS = 1000
SIZES = (500,)
SEED = 42

OPERATIONS = {
    "pa", "pb", "sa", "sb", "ss",
    "ra", "rb", "rr", "rra", "rrb", "rrr",
}


def make_values(size, rng):
    """Make unique values with both signs, then shuffle their order."""
    half = size // 2
    values = list(range(-half, 0)) + list(range(1, size - half + 1))
    rng.shuffle(values)
    return values


def run_one(values):
    command = [EXECUTABLE, *(str(value) for value in values)]
    process = subprocess.Popen(
        command,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )

    printed_operations = 0
    for line in process.stdout:
        if line.strip() in OPERATIONS:
            printed_operations += 1
    process.stdout.close()

    stderr = process.stderr.read()
    process.stderr.close()
    return_code = process.wait()

    reported_match = re.search(r"Operations:\s*(\d+)", stderr)
    reported_operations = int(reported_match.group(1)) if reported_match else None
    result_match = re.search(r"Result:\s*(OK|KO)", stderr)
    result = result_match.group(1) if result_match else "UNKNOWN"

    return {
        "printed_operations": printed_operations,
        "reported_operations": reported_operations,
        "result": result,
        "return_code": return_code,
        "count_match": reported_operations == printed_operations,
        "stderr": stderr.strip(),
    }


def write_summary(size, rows, output_path):
    successful = [row for row in rows if row["result"] == "OK" and row["return_code"] == 0]
    if not successful:
        output_path.write_text(
            f"{size} elements: no successful runs. Check the CSV for details.\n",
            encoding="utf-8",
        )
        return

    worst = sorted(successful, key=lambda row: row["printed_operations"], reverse=True)[:5]
    best = sorted(successful, key=lambda row: row["printed_operations"])[:5]
    counts = [row["printed_operations"] for row in successful]
    mismatches = sum(not row["count_match"] for row in successful)

    lines = [
        f"Turk Sort benchmark — {size} elements",
        f"Runs requested: {RUNS}",
        f"Successful runs: {len(successful)}",
        f"Random seed: {SEED}",
        f"Average printed operations: {mean(counts):.2f}",
        f"Median printed operations: {median(counts):.2f}",
        f"Lowest printed operations: {min(counts)}",
        f"Highest printed operations: {max(counts)}",
        f"Reported/printed count mismatches: {mismatches}",
        "",
        "Five highest operation counts (worst):",
    ]
    for row in worst:
        lines.append(
            f"  Run {row['run']}: {row['printed_operations']} operations; "
            f"reported={row['reported_operations']}; input={row['input']}"
        )

    lines.extend(["", "Five lowest operation counts (best):"])
    for row in best:
        lines.append(
            f"  Run {row['run']}: {row['printed_operations']} operations; "
            f"reported={row['reported_operations']}; input={row['input']}"
        )

    output_path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def main():
    if not Path(EXECUTABLE).is_file():
        raise SystemExit(f"Cannot find {EXECUTABLE}. Build your test harness first.")

    rng = random.Random(SEED)
    all_summaries = []

    for size in SIZES:
        csv_path = Path(f"turk_benchmark_{size}.csv")
        summary_path = Path(f"turk_benchmark_{size}_summary.txt")
        rows = []

        print(f"\nTesting {RUNS} permutations of {size} elements...", flush=True)
        with csv_path.open("w", newline="", encoding="utf-8") as csv_file:
            fields = [
                "run", "result", "printed_operations", "reported_operations",
                "count_match", "return_code", "input",
            ]
            writer = csv.DictWriter(csv_file, fieldnames=fields)
            writer.writeheader()

            for run_number in range(1, RUNS + 1):
                values = make_values(size, rng)
                result = run_one(values)
                row = {
                    "run": run_number,
                    "result": result["result"],
                    "printed_operations": result["printed_operations"],
                    "reported_operations": result["reported_operations"],
                    "count_match": result["count_match"],
                    "return_code": result["return_code"],
                    "input": " ".join(str(value) for value in values),
                }
                writer.writerow(row)
                csv_file.flush()
                rows.append(row | result)

                if run_number % 50 == 0 or run_number == RUNS:
                    print(f"  {run_number}/{RUNS} complete", flush=True)

        write_summary(size, rows, summary_path)
        all_summaries.append(summary_path)
        print(f"Saved: {csv_path} and {summary_path}", flush=True)

    print("\nBenchmark finished. Summaries:")
    for path in all_summaries:
        print(f"  {path}")


if __name__ == "__main__":
    main()
