# Sum of Three Values

## Problem

Given an array of `n` integers, find three values at distinct positions whose sum is equal to `x`.

Print the original positions of these three values.

If there are several valid answers, any one of them may be printed. If no such triple exists, print `IMPOSSIBLE`.

---

## Problem Type

- Sorting
- Two Pointers
- Three Sum

---

## Core Idea

Store each value together with its original position.

After sorting the values, fix one value and use the two-pointer technique to find two additional values whose sum completes the target.

The original positions must be preserved because sorting changes the order of the array.

---

## Algorithm Template

```text
Read n and x

Store each value with its original position

Sort values by value

For each fixed index

    left = fixed index + 1

    right = n - 1

    While left < right

        currentSum = fixed value + left value + right value

        If currentSum == x

            Print original positions

            Stop

        Else if currentSum < x

            Move left pointer

        Else

            Move right pointer

Print IMPOSSIBLE if no triple was found
```

---

## Key Idea

Technique:
- Sorting
- Two Pointers
- Index Preservation

Mathematical / Algorithmic Insight:
- Fixing one value reduces the problem to finding two values with a specific remaining sum.
- Sorting allows the two-pointer search to be performed efficiently.
- If the current sum is too small, increasing the smaller pointer is the only useful move.
- If the current sum is too large, decreasing the larger pointer is the only useful move.
- Storing original indices ensures that the required positions can still be printed after sorting.

---

## Common Mistakes

- Printing sorted positions instead of original positions.
- Using the same element more than once.
- Forgetting that output positions are 1-based.
- Using `int` for sums when values can be up to `10^9`.
- Starting the left pointer before the fixed index, which can reuse elements.

---

## Time Complexity

**O(n²)**

**Justification:**

For each fixed value, the two-pointer scan is linear. Therefore, the total running time is `O(n²)`.

---

## Memory Complexity

**O(n)**

**Justification:**

The algorithm stores each value together with its original index.

---

## Reference Implementation

See [`sum_of_three_values.cpp`](../src/sum_of_three_values.cpp).

---