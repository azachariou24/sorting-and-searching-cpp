# Josephus Problem I

## Problem

There are `n` children standing in a circle.

Starting from child `1`, every second child is removed until no children remain.

Print the order in which the children are removed.

---

## Problem Type

- Simulation
- Circular Data Structure
- Linked List

---

## Core Idea

Model the children as a circular sequence.

Repeatedly move to the next child, remove that child, and continue from the child immediately after the removed one.

A linked list allows constant-time removals while preserving the circular traversal.

---

## Algorithm Template

```text
Create a list containing 1 to n

current = first child

While the list is not empty

    Move to the next child

    Wrap around if necessary

    Print this child

    Remove this child

    Continue from the following child

    Wrap around if necessary
```

---

## Key Idea

Technique:
- Simulation
- Linked List

Mathematical / Algorithmic Insight:
- The circle changes after every removal.
- Removing elements efficiently is more important than random access.
- A linked list supports constant-time deletion once the iterator is known.
- The iterator wraps back to the beginning whenever it reaches the end of the list.

---

## Common Mistakes

- Forgetting that the circle wraps around.
- Invalidating the iterator after erasing an element.
- Continuing from the removed child instead of the next remaining child.
- Using a vector, which requires expensive element shifts after every removal.

---

## Time Complexity

**O(n)**

**Justification:**

Each child is visited and removed exactly once. Iterator movement and removal are constant-time operations.

---

## Memory Complexity

**O(n)**

**Justification:**

The linked list stores all `n` children.

---

## Reference Implementation

See [`josephus_problem_i.cpp`](../src/josephus_problem_i.cpp).

---