# Subarray Distinct Values

## Problem

Given an array of `n` integers, count the number of contiguous subarrays that contain at most `k` distinct values.

---

## Problem Type

- Sliding Window
- Two Pointers
- Frequency Map
- Counting Subarrays

---

## Core Idea

Maintain a sliding window that contains at most `k` distinct values.

As the right boundary expands, update the frequency of the new value. If the number of distinct values becomes greater than `k`, move the left boundary until the window becomes valid again.

For each right endpoint, every subarray ending there and starting inside the current valid window is valid.

---

## Algorithm Template

```text
Read the array

frequency = empty map

left = 0

distinctValues = 0

answer = 0

For right from 0 to n - 1

    Add values[right] to frequency

    If it appears for the first time

        Increase distinctValues

    While distinctValues > k

        Remove values[left] from frequency

        If its frequency becomes zero

            Decrease distinctValues

        Move left forward

    Add right - left + 1 to answer

Print answer
```

---

## Key Idea

Technique:
- Sliding Window
- Frequency Map
- Counting

Mathematical / Algorithmic Insight:
- The current window is always the longest valid window ending at the current right endpoint.
- Every suffix of a valid window is also valid because removing elements cannot increase the number of distinct values.
- Therefore, the number of valid subarrays ending at `right` is exactly the window length.
- Each pointer moves only forward, making the scan efficient.

---

## Common Mistakes

- Counting only the longest valid window instead of all valid subarrays.
- Forgetting to decrease the number of distinct values when a frequency becomes zero.
- Moving the left boundary only once when multiple removals may be needed.
- Using `int` for the answer, which may overflow.
- Confusing "at most k distinct values" with "exactly k distinct values".

---

## Time Complexity

**O(n log n)**

**Justification:**

Each element is inserted into and removed from an ordered map at most once. Each map operation takes `O(log n)` time.

---

## Memory Complexity

**O(n)**

**Justification:**

In the worst case, the frequency map may store up to `n` distinct values.

---

## Reference Implementation

See [`subarray_distinct_values.cpp`](../src/subarray_distinct_values.cpp).

---