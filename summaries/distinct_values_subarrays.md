# Distinct Values Subarrays

## Problem

Given an array of `n` integers, count the number of contiguous subarrays where every element is distinct.

---

## Problem Type

- Sliding Window
- Ordered Map
- Two Pointers
- Counting Subarrays

---

## Core Idea

Maintain a sliding window that always contains only distinct values.

For each right endpoint, after moving the left boundary if needed, all subarrays ending at that position and starting anywhere inside the current window are valid.

Therefore, if the current window length is `right − left + 1`, we add that value to the answer.

---

## Algorithm Template

```text
Read the array

left = 0

answer = 0

lastPosition = empty map

For right from 0 to n - 1

    If current value appeared before

        Move left to max(left, lastPosition[current value] + 1)

    Update lastPosition[current value]

    Add right - left + 1 to answer

Print answer
```

---

## Key Idea

Technique:
- Sliding Window
- Ordered Map
- Counting

Mathematical / Algorithmic Insight:
- The current window always contains distinct values.
- Once the window is valid for a fixed right endpoint, every suffix of the window ending at right is also valid.
- The number of such suffixes is exactly the window length.
- The left boundary never moves backwards, so the scan is efficient.

---

## Common Mistakes

- Counting only the longest distinct subarray instead of all distinct subarrays.
- Restarting the window completely after finding a duplicate.
- Moving the left boundary backwards.
- Forgetting that the answer can be larger than `int`.
- Using nested loops to check every subarray.

---

## Time Complexity

**O(n log n)**

**Justification:**

Each element is processed once. Every lookup and update in the ordered map takes `O(log n)` time.

---

## Memory Complexity

**O(n)**

**Justification:**

The ordered map may store the latest position of each distinct value.

---

## Reference Implementation

See [`distinct_values_subarrays.cpp`](../src/distinct_values_subarrays.cpp).

---