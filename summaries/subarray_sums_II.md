# Subarray Sums II

## Problem

Given an array of `n` integers, count the number of contiguous subarrays whose sum is exactly `x`.

The array may contain positive, negative, or zero values.

---

## Problem Type

- Prefix Sums
- Ordered Map
- Counting

---

## Core Idea

Use prefix sums.

For two positions `i < j`, the sum of the subarray between them is:

```text
prefix[j] - prefix[i]
```

We want this value to equal `x`, so for each current prefix sum, we count how many previous prefix sums are equal to:

```text
currentPrefix - x
```

---

## Algorithm Template

```text
prefixFrequency[0] = 1

currentPrefix = 0

answer = 0

For each value

    currentPrefix += value

    answer += frequency of currentPrefix - x

    Increase frequency of currentPrefix

Print answer
```

---

## Key Idea

Technique:
- Prefix Sums
- Frequency Map

Mathematical / Algorithmic Insight:
- A subarray sum can be represented as the difference of two prefix sums.
- If the current prefix sum is `S`, then a previous prefix sum `S - x` forms a subarray with sum `x`.
- Counting frequencies of previous prefix sums allows all valid subarrays ending at the current position to be counted efficiently.
- This method works even when negative numbers are present.

---

## Common Mistakes

- Using sliding window even though negative numbers are allowed.
- Forgetting to initialize `prefixFrequency[0] = 1`.
- Updating the current prefix frequency before counting valid subarrays.
- Using `int` instead of `long long`.
- Counting only one occurrence of a prefix sum instead of its full frequency.

---

## Time Complexity

**O(n log n)**

**Justification:**

Each prefix sum is inserted into and queried from an ordered map, which takes `O(log n)` time.

---

## Memory Complexity

**O(n)**

**Justification:**

In the worst case, all prefix sums are distinct and must be stored.

---

## Reference Implementation

See [`subarray_sums_ii.cpp`](../src/subarray_sums_II.cpp).

---