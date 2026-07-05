# Subarray Sums I

## Problem

Given an array of `n` positive integers, count the number of contiguous subarrays whose sum is exactly `x`.

---

## Problem Type

- Sliding Window
- Two Pointers
- Positive Numbers

---

## Core Idea

Because all array values are positive, increasing the right boundary of a window increases the sum, while increasing the left boundary decreases the sum.

This monotonic behavior allows a sliding window solution.

---

## Algorithm Template

```text
Read the array

left = 0

currentSum = 0

answer = 0

For right from 0 to n - 1

    Add values[right] to currentSum

    While currentSum > x

        Remove values[left] from currentSum

        Move left forward

    If currentSum == x

        Increase answer

Print answer
```

---

## Key Idea

Technique:
- Sliding Window
- Two Pointers

Mathematical / Algorithmic Insight:
- Since all values are positive, expanding the window can only increase the sum.
- Shrinking the window from the left can only decrease the sum.
- Therefore, each pointer moves only forward.
- Every valid subarray is counted exactly when its right endpoint is processed.

---

## Common Mistakes

- Using this sliding window approach when negative numbers are allowed.
- Forgetting that all values are positive.
- Using nested loops, which is too slow.
- Using `int` for sums when values can be large.
- Moving the left pointer only once instead of while the sum is too large.

---

## Time Complexity

**O(n)**

**Justification:**

Both pointers move from left to right at most once.

---

## Memory Complexity

**O(n)**

**Justification:**

The array is stored in a vector. The algorithm itself uses only constant extra memory.

---

## Reference Implementation

See [`subarray_sums_I.cpp`](../src/subarray_sums_I.cpp).

---
