# Subarray Divisibility

## Problem

Given an array of `n` integers, count the number of contiguous subarrays whose sum is divisible by `n`.

---

## Problem Type

- Prefix Sums
- Modular Arithmetic
- Counting

---

## Core Idea

Use prefix sums modulo `n`.

If two prefix sums have the same remainder modulo `n`, then their difference is divisible by `n`.

Therefore, every pair of equal remainders corresponds to a subarray whose sum is divisible by `n`.

---

## Algorithm Template

```text
remainderFrequency[0] = 1

currentPrefix = 0

answer = 0

For each value

    currentPrefix += value

    remainder = currentPrefix modulo n

    Normalize remainder to be nonnegative

    answer += remainderFrequency[remainder]

    Increase remainderFrequency[remainder]

Print answer
```

---

## Key Idea

Technique:
- Prefix Sums
- Modular Arithmetic
- Frequency Counting

Mathematical / Algorithmic Insight:
- The sum of a subarray can be written as the difference of two prefix sums.
- A difference is divisible by `n` exactly when both prefix sums have the same remainder modulo `n`.
- Counting how many times each remainder has appeared allows all valid subarrays ending at the current position to be counted efficiently.
- Remainders must be normalized because array values may be negative.

---

## Common Mistakes

- Forgetting to initialize the frequency of remainder `0` to `1`.
- Not handling negative values correctly when computing modulo in C++.
- Trying all subarrays explicitly.
- Using `int` for the answer, which may overflow.
- Confusing divisibility by `n` with divisibility by the current index.

---

## Time Complexity

**O(n)**

**Justification:**

The array is scanned once, and each operation on the frequency vector is constant time.

---

## Memory Complexity

**O(n)**

**Justification:**

The frequency vector stores counts for all possible remainders from `0` to `n - 1`.

---

## Reference Implementation

See [`subarray_divisibility.cpp`](../src/subarray_divisibility.cpp).

---