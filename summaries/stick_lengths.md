# Stick Lengths

## Problem

There are `n` sticks with different lengths.

You may either lengthen or shorten each stick. The cost of changing a stick is the absolute difference between its original length and its new length.

Determine the minimum total cost required to make all sticks have the same length.

---

## Problem Type

- Sorting
- Greedy
- Median

---

## Core Idea

To minimize the total absolute difference between all stick lengths and a chosen target length, the optimal target is the median.

After sorting the stick lengths, choose the middle value as the target length and compute the total cost.

---

## Algorithm Template

```text
Read all stick lengths

Sort the lengths

targetLength = median value

totalCost = 0

For each stick length

    Add absolute difference from targetLength to totalCost

Print totalCost
```

---

## Key Idea

Technique:
- Sorting
- Greedy
- Median Optimization

Mathematical / Algorithmic Insight:
- The expression to minimize is the sum of absolute differences.
- For one-dimensional data, the sum of absolute distances is minimized at the median.
- If `n` is even, any value between the two middle values is optimal, so choosing `sticks[n / 2]` is valid.
- This avoids trying all possible target lengths.

---

## Common Mistakes

- Using the average instead of the median.
- Trying every possible target length, which is too slow.
- Using `int` for the total cost, which may overflow.
- Forgetting to use absolute differences.
- Assuming the target length must be newly computed instead of choosing an existing median value.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting the stick lengths takes `O(n log n)`. Computing the total cost takes one linear scan.

---

## Memory Complexity

**O(n)**

**Justification:**

The stick lengths are stored in a vector of size `n`. The algorithm itself uses only constant extra memory besides the input storage.

---

## Reference Implementation

See [`stick_lengths.cpp`](../src/stick_lengths.cpp).

---