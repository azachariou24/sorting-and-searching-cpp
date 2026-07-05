# Nested Ranges Count

## Problem

Given `n` ranges, determine for each range:

- how many other ranges it contains
- how many other ranges contain it

Range `[a, b]` contains range `[c, d]` if `a <= c` and `d <= b`.

---

## Problem Type

- Sorting
- Intervals
- Fenwick Tree
- Coordinate Compression

---

## Core Idea

Sort the ranges by increasing left endpoint.

If two ranges have the same left endpoint, sort the one with the larger right endpoint first.

After sorting, containment can be counted by comparing right endpoints. A Fenwick Tree is used to efficiently count how many right endpoints are smaller than or greater than the current one.

---

## Algorithm Template

```text
Read all ranges with original indices

Compress all right endpoints

Sort ranges by left endpoint ascending

If left endpoints are equal, sort by right endpoint descending

Scan from right to left

    Count later ranges with right endpoint <= current right

    This gives how many ranges the current range contains

Scan from left to right

    Count previous ranges with right endpoint >= current right

    This gives how many ranges contain the current range

Print answers in original input order
```

---

## Key Idea

Technique:
- Sorting
- Fenwick Tree
- Coordinate Compression

Mathematical / Algorithmic Insight:
- After sorting by left endpoint, later ranges start no earlier than the current range.
- Therefore, a later range is contained by the current range exactly when its right endpoint is at most the current right endpoint.
- Similarly, a previous range contains the current range exactly when its right endpoint is at least the current right endpoint.
- Coordinate compression is needed because right endpoints can be as large as `10^9`.
- The Fenwick Tree allows prefix counting of right endpoints in logarithmic time.

---

## Common Mistakes

- Forgetting to preserve the original input order.
- Sorting equal left endpoints by increasing right endpoint.
- Trying to compare every pair of ranges.
- Forgetting coordinate compression.
- Confusing the two output lines.
- Using strict inequalities instead of allowing equality.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting and coordinate compression take `O(n log n)`. Each Fenwick Tree update and query takes `O(log n)`, and there are `O(n)` such operations.

---

## Memory Complexity

**O(n)**

**Justification:**

The algorithm stores the ranges, compressed endpoints, answer arrays, and Fenwick Tree arrays.

---

## Reference Implementation

See [`nested_ranges_count.cpp`](../src/nested_ranges_count.cpp).

---