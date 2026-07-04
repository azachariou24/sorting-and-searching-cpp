# Maximum Subarray Sum

## Problem

Given an array of `n` integers, find the maximum sum of values in a contiguous, nonempty subarray.

---

## Problem Type

- Dynamic Programming
- Kadane's Algorithm
- Linear Scan

---

## Core Idea

At each position, decide whether it is better to extend the previous subarray or start a new subarray from the current value.

The best answer is the maximum subarray sum found during this scan.

---

## Algorithm Template

```text
Read the array

currentSum = first value

bestSum = first value

For each remaining value

    currentSum = max(current value, currentSum + current value)

    bestSum = max(bestSum, currentSum)

Print bestSum
```

---

## Key Idea

Technique:
- Dynamic Programming
- Kadane's Algorithm

Mathematical / Algorithmic Insight:
- Any maximum subarray ending at the current position either starts at the current value or extends the best subarray ending at the previous position.
- This gives the recurrence:

  `currentSum = max(value, currentSum + value)`

- Initializing with the first element correctly handles arrays where all values are negative.

---

## Common Mistakes

- Initializing the answer to `0`, which fails when all values are negative.
- Allowing an empty subarray even though the problem requires a nonempty subarray.
- Using `int` for the sum, which may overflow.
- Restarting the subarray incorrectly after a negative value without checking whether extension is still better.

---

## Time Complexity

**O(n)**

**Justification:**

The algorithm scans the array once and performs constant-time work for each element.

---

## Memory Complexity

**O(n)**

**Justification:**

The array is stored in a vector of size `n`. The dynamic programming state itself uses only constant extra memory.

---

## Reference Implementation

See [`maximum_subarray_sum.cpp`](../src/maximum_subarray_sum.cpp).

---