# Sum of Two Values

## Problem

Given an array of `n` integers, find two values at distinct positions whose sum is equal to `x`.

Print the original positions of these two values.

If there are several valid answers, any one of them may be printed. If no such pair exists, print `IMPOSSIBLE`.

---

## Problem Type

- Sorting
- Two Pointers

---

## Core Idea

Store each value together with its original position.

After sorting the values, use two pointers to search for a pair whose sum is equal to `x`.

The original positions must be preserved because sorting changes the order of the array.

---

## Algorithm Template

```text
Read n and x

For each value

    Store value together with its original position

Sort values by value

left = 0

right = n - 1

While left < right

    currentSum = values[left] + values[right]

    If currentSum == x

        Print original positions

        Stop

    Else if currentSum < x

        Move left pointer

    Else

        Move right pointer

Print IMPOSSIBLE if no pair was found
```

---

## Key Idea

Technique:
- Sorting
- Two Pointers
- Index Preservation

Mathematical / Algorithmic Insight:
- Sorting allows the pair search to be performed efficiently.
- If the current sum is too small, increasing the smaller value is the only useful move.
- If the current sum is too large, decreasing the larger value is the only useful move.
- Storing original indices ensures that the required positions can still be printed after sorting.

---

## Common Mistakes

- Printing sorted positions instead of original positions.
- Using the same element twice.
- Forgetting that positions are 1-based in the output.
- Using `int` for sums when values can be up to `10^9`.
- Continuing after finding a valid pair and printing extra output.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting the array takes `O(n log n)`. The two-pointer scan is linear.

---

## Memory Complexity

**O(n)**

**Justification:**

The algorithm stores each value together with its original index.

---

## Reference Implementation

See [`sum_of_two_values.cpp`](../src/sum_of_two_values.cpp).

---