# Traffic Lights

## Problem

There is a street of length `x`, with positions numbered from `0` to `x`.

Initially, there are no traffic lights. Then `n` traffic lights are added one by one at distinct positions.

After each insertion, determine the length of the longest passage without traffic lights.

---

## Problem Type

- Ordered Set
- Ordered Multiset
- Greedy
- Dynamic Intervals

---

## Core Idea

Maintain the positions of all traffic lights in an ordered set.

Also maintain the lengths of all passages between consecutive traffic lights in a multiset.

Whenever a new traffic light is inserted, it splits exactly one existing passage into two smaller passages. Remove the old passage, insert the two new passages, and report the largest remaining passage.

---

## Algorithm Template

```text
Insert positions 0 and x into the set

Insert the initial passage of length x into the multiset

For each new traffic light

    Find the nearest traffic light to the right

    Find the nearest traffic light to the left

    Remove the old passage

    Insert the two new passages

    Insert the new traffic light

    Print the largest passage
```

---

## Key Idea

Technique:
- Ordered Set
- Ordered Multiset
- Greedy

Mathematical / Algorithmic Insight:
- Every new traffic light affects only one interval: the interval in which it is placed.
- This interval is replaced by exactly two smaller intervals.
- The ordered set allows efficient access to the neighboring traffic lights.
- The multiset efficiently maintains all current passage lengths, even when multiple passages have the same length.
- The largest passage is always the largest element in the multiset.

---

## Common Mistakes

- Recomputing every interval after each insertion, leading to an inefficient solution.
- Using a `set` instead of a `multiset` for passage lengths, which fails when duplicate lengths exist.
- Forgetting to insert the street boundaries `0` and `x`.
- Removing all intervals of the same length instead of only the affected one.
- Using `lower_bound` instead of `upper_bound` to find the neighboring traffic lights.

---

## Time Complexity

**O(n log n)**

**Justification:**

Each insertion performs a constant number of ordered set and multiset operations, each requiring `O(log n)` time.

---

## Memory Complexity

**O(n)**

**Justification:**

The ordered set stores all traffic light positions, while the multiset stores the current passage lengths.

---

## Reference Implementation

See [`traffic_lights.cpp`](../src/traffic_lights.cpp).

---