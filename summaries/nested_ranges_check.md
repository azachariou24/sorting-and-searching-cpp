# Nested Ranges Check

## Problem

Given `n` ranges, determine for each range:

- whether it contains some other range
- whether it is contained in some other range

Range `[a, b]` contains range `[c, d]` if `a <= c` and `d <= b`.

---

## Problem Type

- Sorting
- Intervals
- Sweep Line

---

## Core Idea

Sort ranges by increasing left endpoint.

If two ranges have the same left endpoint, sort the one with the larger right endpoint first.

After sorting:

- A range is contained by another range if a previous range has a right endpoint at least as large.
- A range contains another range if a later range has a right endpoint at most as large.

---

## Algorithm Template

```text
Read all ranges with their original indices

Sort by left endpoint ascending

If left endpoints are equal, sort by right endpoint descending

maximumRight = 0

Scan from left to right

    If current right <= maximumRight

        Current range is contained by another range

    Update maximumRight

minimumRight = infinity

Scan from right to left

    If current right >= minimumRight

        Current range contains another range

    Update minimumRight

Print answers in original input order
```

---

## Key Idea

Technique:
- Sorting
- Prefix Maximum
- Suffix Minimum

Mathematical / Algorithmic Insight:
- Sorting by left endpoint ensures that earlier ranges start no later than later ranges.
- For the contained check, if an earlier range also ends no earlier, then it contains the current range.
- For the contains check, if a later range ends no later, then the current range contains that later range.
- Sorting equal left endpoints by decreasing right endpoint is necessary so larger ranges are considered before smaller ranges.

---

## Common Mistakes

- Forgetting to preserve original input order.
- Sorting equal left endpoints by increasing right endpoint.
- Checking every pair of ranges, which is too slow.
- Confusing the two output lines.
- Using strict inequalities instead of allowing equality.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting the ranges takes `O(n log n)`. Both scans are linear.

---

## Memory Complexity

**O(n)**

**Justification:**

The algorithm stores the ranges and two answer arrays.

---

## Reference Implementation

See [`nested_ranges_check.cpp`](../src/nested_ranges_check.cpp).

---