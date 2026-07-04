# Distinct Values Subsequences

## Problem

Given an array of `n` integers, count the number of subsequences where every selected element is distinct.

A subsequence may skip elements, but the selected elements must remain in their original left-to-right order.

The answer may be large, so print it modulo `10^9 + 7`.

---

## Problem Type

- Combinatorics
- Frequency Counting
- Modular Arithmetic

---

## Core Idea

For each distinct value, suppose it appears `f` times.

In a valid subsequence, this value can be chosen at most once. Therefore, for this value, there are `f + 1` choices:

- choose none of its occurrences
- choose one of its `f` occurrences

Multiplying these choices over all distinct values gives all valid subsequences, including the empty subsequence. Finally, subtract one to remove the empty subsequence.

---

## Algorithm Template

```text
Count the frequency of every value

answer = 1

For each distinct value

    answer = answer * (frequency + 1)

Remove the empty subsequence

Print answer modulo 10^9 + 7
```

---

## Key Idea

Technique:
- Frequency Counting
- Product Rule
- Modular Arithmetic

Mathematical / Algorithmic Insight:
- Since each value may appear at most once in the subsequence, choices are independent across distinct values.
- A value with frequency `f` contributes `f + 1` choices.
- The product rule counts all possible selections of positions with no repeated value.
- The original order is automatically preserved because any chosen positions form a subsequence in increasing index order.

---

## Common Mistakes

- Confusing subsequences with subarrays.
- Using sliding window, which only applies to contiguous subarrays.
- Forgetting to subtract the empty subsequence.
- Trying to generate subsequences explicitly.
- Forgetting to take modulo `10^9 + 7`.

---

## Time Complexity

**O(n log n)**

**Justification:**

Each value is inserted into an ordered map, which takes `O(log n)` time.

---

## Memory Complexity

**O(n)**

**Justification:**

In the worst case, all values are distinct, so the frequency map stores `n` entries.

---

## Reference Implementation

See [`distinct_values_subsequences.cpp`](../src/distinct_values_subsequences.cpp).

---