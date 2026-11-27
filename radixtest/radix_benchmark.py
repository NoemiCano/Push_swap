#!/usr/bin/env python3
"""Local Push_swap Radix benchmark. No external dependencies."""
import random


def run_binary_lsd(values):
    a = list(values)  # top is index 0
    b = []
    ops = []
    max_index = max(a, default=0)
    bit_count = max_index.bit_length()

    for bit in range(bit_count):
        n = len(a)
        for _ in range(n):
            value = a[0]
            if (value >> bit) & 1:
                a.append(a.pop(0))
                ops.append("ra")
            else:
                b.insert(0, a.pop(0))
                ops.append("pb")
        while b:
            a.insert(0, b.pop(0))
            ops.append("pa")

    return a, ops


def run_grouped_two_bit(values):
    """Two-bit digit grouping, mechanically implemented as stable bit passes.
    This is NOT a true four-bucket stack algorithm; it is a reference baseline.
    """
    a = list(values)
    b = []
    ops = []
    max_index = max(a, default=0)
    bit_count = max_index.bit_length()

    bit = 0
    while bit < bit_count:
        # Grouping the loop in pairs changes pass bookkeeping only.
        for sub_bit in range(bit, min(bit + 2, bit_count)):
            n = len(a)
            for _ in range(n):
                value = a[0]
                if (value >> sub_bit) & 1:
                    a.append(a.pop(0))
                    ops.append("ra")
                else:
                    b.insert(0, a.pop(0))
                    ops.append("pb")
            while b:
                a.insert(0, b.pop(0))
                ops.append("pa")
        bit += 2

    return a, ops



def benchmark(size, runs):
    totals = []
    failures = 0
    for _ in range(runs):
        sample = list(range(size))
        random.shuffle(sample)
        result, ops = run_binary_lsd(sample)
        if result != list(range(size)):
            failures += 1
        totals.append(len(ops))

    grouped_result, grouped_ops = run_grouped_two_bit(list(range(size - 1, -1, -1)))
    if grouped_result != list(range(size)):
        failures += 1

    target = 700 if size == 100 else 5500 if size == 500 else None
    passed = target is not None and len(grouped_ops) < target
    print(f"Size: {size}, runs: {runs}")
    print(f"Binary LSD min/avg/max: {min(totals)}/{sum(totals)/len(totals):.1f}/{max(totals)}")
    print(f"Two-bit grouped baseline: {len(grouped_ops)} ops (same operations as binary passes)")
    if target is not None:
        print(f"Excellent threshold (<{target}): {'PASS' if passed else 'FAIL'}")
    print(f"Correctness failures: {failures}")
    print()


if __name__ == "__main__":
    random.seed()
    benchmark(100, 1000)
    benchmark(500, 1000)
