# Distinct Numbers

## Problem

Given a list of `n` integers, determine how many distinct values appear in the list.

Print the number of unique values.

---

## Problem Type

- Sorting
- Arrays

---

## Core Idea

After sorting the array, equal values become adjacent. A single linear scan is then sufficient to count how many times a new value appears.

---

## Algorithm Template

```text
Read the array

Sort the array

Initialize distinct = 1

For each element starting from the second

    If current element differs from previous

        Increase distinct

Print distinct
```

---

## Key Idea

Technique:
- Sorting
- Linear Scan

Mathematical / Algorithmic Insight:
- Sorting groups identical values together.
- Every time two consecutive elements differ, a new distinct value has been found.
- Therefore, counting value changes after sorting gives the exact number of unique elements.

---

## Common Mistakes

- Forgetting to sort before counting.
- Comparing every element with every other element, resulting in `O(n²)` time.
- Forgetting that the first element is always a distinct value.
- Accessing `numbers[i - 1]` when `i = 0`.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting dominates the running time with `O(n log n)`, while the subsequent traversal requires only `O(n)`.

---

## Memory Complexity

**O(n)**

**Justification:**

The input is stored in a vector of size `n`. The sorting algorithm additionally requires only logarithmic stack space.

---

## Reference Implementation

See [`distinct_numbers.cpp`](../src/distinct_numbers.cpp).

---