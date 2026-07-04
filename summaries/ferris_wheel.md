# Ferris Wheel

## Problem

There are `n` children who want to ride a Ferris wheel.

Each gondola can contain either one or two children, and the total weight in a gondola must not exceed `x`.

Determine the minimum number of gondolas needed for all children.

---

## Problem Type

- Sorting
- Greedy
- Two Pointers

---

## Core Idea

Sort the children by weight.

Then repeatedly assign the heaviest remaining child to a gondola. If the lightest remaining child can ride together with the heaviest one, pair them. Otherwise, the heaviest child must ride alone.

---

## Algorithm Template

```text
Read the weights

Sort the weights

left = 0

right = n - 1

gondolas = 0

While left <= right

    If weights[left] + weights[right] <= x

        Move left pointer

        Move right pointer

    Else

        Move right pointer

    Increase gondolas

Print gondolas
```

---

## Key Idea

Technique:
- Sorting
- Greedy
- Two Pointers

Mathematical / Algorithmic Insight:
- The heaviest remaining child must be assigned to some gondola.
- Pairing the heaviest child with the lightest possible child is always safe if they fit together.
- If the heaviest child cannot fit with the lightest child, then they cannot fit with any other remaining child and must ride alone.
- Each iteration uses exactly one gondola and removes at least the heaviest remaining child.

---

## Common Mistakes

- Pairing children in input order instead of sorting them first.
- Trying all possible pairs, which leads to an inefficient `O(n²)` solution.
- Forgetting that each gondola can contain at most two children.
- Moving both pointers even when the heaviest child must ride alone.
- Using `left < right` instead of `left <= right`, which can miss the final unpaired child.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting the weights takes `O(n log n)`. After sorting, the two-pointer traversal processes each child at most once.

---

## Memory Complexity

**O(n)**

**Justification:**

The weights are stored in a vector of size `n`. The algorithm itself uses only constant extra memory besides the input storage.

---

## Reference Implementation

See [`ferris_wheel.cpp`](../src/ferris_wheel.cpp).

---