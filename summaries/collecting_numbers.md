# Collecting Numbers

## Problem

You are given a permutation containing every number from `1` to `n` exactly once.

On each round, you scan the array from left to right and collect as many numbers as possible in increasing order.

Determine the total number of rounds needed to collect all numbers from `1` to `n`.

---

## Problem Type

- Permutation
- Position Mapping
- Linear Scan

---

## Core Idea

Store the position of each number in the permutation.

If number `i` appears before number `i − 1`, then `i` cannot be collected in the same left-to-right scan as `i − 1`.

Therefore, this creates a new round.

---

## Algorithm Template

```text
Read the permutation

For each value

    Store its position

rounds = 1

For value from 2 to n

    If position[value] < position[value - 1]

        Increase rounds

Print rounds
```

---

## Key Idea

Technique:
- Position Array
- Permutation Analysis
- Linear Scan

Mathematical / Algorithmic Insight:
- During one left-to-right scan, numbers can be collected only if their positions appear in increasing order.
- Whenever `position[i] < position[i - 1]`, the sequence of required numbers breaks.
- Each such break forces a new round.
- The total number of rounds is `1 +` the number of breaks between consecutive values.

---

## Common Mistakes

- Simulating each round explicitly, which can be too slow.
- Sorting the permutation and losing the original positions.
- Comparing values directly instead of comparing their positions.
- Starting the number of rounds from `0` instead of `1`.
- Forgetting that the array is a permutation, so each value has exactly one position.

---

## Time Complexity

**O(n)**

**Justification:**

The algorithm reads the permutation once and then scans the values from `2` to `n` once.

---

## Memory Complexity

**O(n)**

**Justification:**

The position array stores the index of each value from `1` to `n`.

---

## Reference Implementation

See [`collecting_numbers.cpp`](../src/collecting_numbers.cpp).

---