# Towers

## Problem

You are given `n` cubes in a fixed order.

Your task is to build towers using the cubes. Whenever one cube is placed on top of another, the upper cube must be strictly smaller than the lower cube.

Each cube must be processed in the given order. For every cube, you may either place it on top of an existing tower or start a new tower.

Determine the minimum possible number of towers.

---

## Problem Type

- Greedy
- Ordered Multiset
- Binary Search

---

## Core Idea

Maintain the current top cube of every tower.

For each cube, place it on the tower whose top cube is the smallest value strictly greater than the current cube.

If no such tower exists, start a new tower.

---

## Algorithm Template

```text
towerTops = empty multiset

For each cube in input order

    Find first tower top greater than cube

    If no such tower exists

        Start a new tower

    Else

        Replace that tower top with cube

Print number of tower tops
```

---

## Key Idea

Technique:
- Greedy
- Multiset
- Binary Search with `upper_bound`

Mathematical / Algorithmic Insight:
- A cube can only be placed on a tower whose top cube is strictly larger.
- To keep future options as flexible as possible, we should place the cube on the valid tower with the smallest possible top.
- This greedy choice preserves larger tower tops for future larger cubes.
- The number of elements in the multiset at the end equals the minimum number of towers.

---

## Common Mistakes

- Using `lower_bound` instead of `upper_bound`, which incorrectly allows equal-sized cubes to be stacked.
- Sorting the cubes first, even though the cubes must be processed in the given order.
- Storing all cubes of each tower instead of only the current top.
- Starting a new tower even when a valid existing tower is available.
- Forgetting that the upper cube must be strictly smaller than the lower cube.

---

## Time Complexity

**O(n log n)**

**Justification:**

Each cube is processed once. For each cube, `upper_bound`, `erase`, and `insert` on the multiset take logarithmic time.

---

## Memory Complexity

**O(n)**

**Justification:**

In the worst case, every cube starts a new tower, so the multiset may store `n` tower tops.

---

## Reference Implementation

See [`towers.cpp`](../src/towers.cpp).

---