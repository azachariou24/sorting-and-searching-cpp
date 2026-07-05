# Maximum Subarray Sum II

## Problem

Given an array of `n` integers, find the maximum sum of a contiguous subarray whose length is between `a` and `b`.

---

## Problem Type

- Prefix Sums
- Ordered Multiset
- Sliding Window
- Range Minimum Query

---

## Core Idea

Use prefix sums.

The sum of a subarray ending at position `right` and starting after position `left` is:

```text
prefix[right] - prefix[left]
```

For the subarray length to be between `a` and `b`, the valid values of `left` must satisfy:

```text
right - b <= left <= right - a
```

For each `right`, we need the minimum prefix sum among these valid `left` positions.

A multiset maintains this moving window of candidate prefix sums.

---

## Algorithm Template

```text
Compute prefix sums

candidatePrefixes = empty multiset

answer = negative infinity

For right from a to n

    Insert prefix[right - a]

    If right - b - 1 >= 0

        Remove prefix[right - b - 1]

    bestPrefix = smallest value in candidatePrefixes

    answer = max(answer, prefix[right] - bestPrefix)

Print answer
```

---

## Key Idea

Technique:
- Prefix Sums
- Sliding Window over Prefix Sums
- Ordered Multiset

Mathematical / Algorithmic Insight:
- Every subarray sum can be written as the difference of two prefix sums.
- For each fixed right endpoint, the length constraint restricts which left endpoints are valid.
- To maximize `prefix[right] - prefix[left]`, we need the smallest valid `prefix[left]`.
- The set of valid left endpoints changes by one insertion and at most one deletion as `right` moves forward.

---

## Common Mistakes

- Using Kadane's algorithm, which does not handle length constraints.
- Forgetting that subarray length must be at least `a` and at most `b`.
- Removing the wrong prefix sum from the multiset.
- Using `int` for prefix sums.
- Forgetting that the array can contain negative numbers.

---

## Time Complexity

**O(n log n)**

**Justification:**

Each prefix sum is inserted into and removed from the multiset at most once. Each operation takes logarithmic time.

---

## Memory Complexity

**O(n)**

**Justification:**

The prefix sums are stored in a vector, and the multiset stores candidate prefix sums.

---

## Reference Implementation

See [`maximum_subarray_sum_II.cpp`](../src/maximum_subarray_sum_II.cpp).

---
