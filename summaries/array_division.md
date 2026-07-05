# Array Division

## Problem

Given an array of `n` positive integers, divide it into `k` contiguous subarrays.

The goal is to minimize the maximum sum among all chosen subarrays.

---

## Problem Type

- Binary Search
- Binary Search on Answer
- Greedy Feasibility Check

---

## Core Idea

Binary search the minimum possible value of the maximum subarray sum.

For a candidate value `M`, greedily scan the array and start a new subarray whenever adding the next element would make the current sum exceed `M`.

If the array can be divided into at most `k` subarrays, then `M` is feasible.

---

## Algorithm Template

```text
Read the array

left = maximum array value

right = total array sum

While left <= right

    middle = candidate maximum subarray sum

    Check if the array can be divided using at most k subarrays

    If possible

        Save middle as answer

        Search smaller values

    Else

        Search larger values

Print answer
```

---

## Key Idea

Technique:
- Binary Search on Answer
- Greedy Partitioning

Mathematical / Algorithmic Insight:
- If a maximum allowed sum `M` is feasible, then any larger value is also feasible.
- This monotonic property allows binary search.
- For a fixed `M`, the greedy strategy of extending the current subarray as much as possible minimizes the number of subarrays used.
- The optimal answer lies between the largest single element and the total sum of the array.

---

## Common Mistakes

- Setting the lower bound to `0` instead of the maximum array value.
- Trying all possible partitions explicitly.
- Forgetting that subarrays must be contiguous.
- Using `int` for sums, which may overflow.
- Checking for exactly `k` subarrays instead of at most `k`.

---

## Time Complexity

**O(n log S)**

**Justification:**

Each feasibility check scans the array in `O(n)`. Binary search is performed over the possible answer range, where `S` is the total array sum.

---

## Memory Complexity

**O(n)**

**Justification:**

The input array is stored in a vector.

---

## Reference Implementation

See [`array_division.cpp`](../src/array_division.cpp).

---