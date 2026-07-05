# Josephus Problem II

## Problem

There are `n` children standing in a circle, numbered from `1` to `n`.

During the game, repeatedly `k` children are skipped and the next child is removed from the circle.

Print the order in which the children are removed.

---

## Problem Type

- Simulation
- Fenwick Tree
- Order Statistics
- Binary Lifting

---

## Core Idea

A direct linked-list simulation is too slow when `k` is large.

Instead, maintain which children are still alive using a Fenwick Tree. Each alive child has value `1`, and each removed child has value `0`.

At every step, compute the order of the next child to remove among the currently alive children, then use the Fenwick Tree to find that child efficiently.

---

## Algorithm Template

```text
Initialize Fenwick Tree with 1 at every position

currentIndex = 0

For aliveChildren from n down to 1

    currentIndex = (currentIndex + k) mod aliveChildren

    removedChild = find the (currentIndex + 1)-th alive child

    Print removedChild

    Mark removedChild as removed in the Fenwick Tree
```

---

## Key Idea

Technique:
- Fenwick Tree
- Order Statistics
- Modular Indexing

Mathematical / Algorithmic Insight:
- The children that remain alive form a dynamic ordered set.
- After skipping `k` alive children, the removed child has order `(currentIndex + k) mod aliveChildren` among the remaining children.
- A Fenwick Tree stores which positions are still alive.
- The `findByOrder` operation finds the position of the `q`-th alive child in `O(log n)` time.
- Removing a child is done by adding `-1` at its position.

---

## Common Mistakes

- Using a linked list and moving `k` steps for every removal, which is too slow when `k` is large.
- Forgetting to use modulo by the current number of alive children.
- Confusing original child numbers with alive-order positions.
- Using zero-based and one-based indexing inconsistently.
- Forgetting to mark removed children as inactive in the Fenwick Tree.

---

## Time Complexity

**O(n log n)**

**Justification:**

There are `n` removals. Each removal performs one Fenwick Tree order query and one update, both taking `O(log n)` time.

---

## Memory Complexity

**O(n)**

**Justification:**

The Fenwick Tree stores one value for each child.

---

## Reference Implementation

See [`josephus_problem_II.cpp`](../src/josephus_problem_II.cpp).

---
