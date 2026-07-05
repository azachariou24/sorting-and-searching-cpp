# Collecting Numbers II

## Problem

You are given a permutation containing every number from `1` to `n` exactly once.

On each round, you scan the array from left to right and collect as many numbers as possible in increasing order.

After each of `m` swap operations, determine the number of rounds needed to collect all numbers.

---

## Problem Type

- Permutation
- Position Mapping
- Incremental Update

---

## Core Idea

The number of rounds is determined by the number of breaks between consecutive values.

A break occurs when value `i + 1` appears before value `i`.

After swapping two positions, only the neighboring value pairs around the swapped values can change. Therefore, we update the answer locally instead of recomputing it from scratch.

---

## Algorithm Template

```text
Read the permutation

Store the position of each value

rounds = 1 + number of breaks

For each swap operation

    Find the two swapped values

    Collect affected neighboring value pairs

    Remove their old contribution from rounds

    Swap the values

    Update their positions

    Add their new contribution to rounds

    Print rounds
```

---

## Key Idea

Technique:
- Position Array
- Local Update
- Permutation Analysis

Mathematical / Algorithmic Insight:
- The number of rounds is `1 +` the number of pairs `(i, i + 1)` such that `position[i] > position[i + 1]`.
- Swapping two values only changes the positions of those two values.
- Therefore, only pairs involving those values and their immediate numerical neighbors can affect the answer.
- Using a set of affected pairs avoids counting the same pair twice.

---

## Common Mistakes

- Recomputing the number of rounds after every swap, leading to `O(nm)` time.
- Forgetting to update both the array and the position array.
- Counting the same affected pair twice.
- Checking unrelated pairs that cannot change.
- Forgetting boundary cases for values `1` and `n`.

---

## Time Complexity

**O(n + m)**

**Justification:**

The initial number of rounds is computed in `O(n)`. Each swap affects only a constant number of neighboring pairs, so each operation is processed in constant time.

---

## Memory Complexity

**O(n)**

**Justification:**

The algorithm stores the permutation and the position of each value.

---

## Reference Implementation

See [`collecting_numbers_ii.cpp`](../src/collecting_numbers_II.cpp).

---