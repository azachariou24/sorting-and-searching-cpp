# Nearest Smaller Values

## Problem

Given an array of `n` integers, determine for each position the nearest position to its left that has a strictly smaller value.

If no such position exists, print `0`.

---

## Problem Type

- Stack
- Monotonic Stack
- Linear Scan

---

## Core Idea

Maintain a stack of candidate previous values.

Before processing the current value, remove all values from the top of the stack that are greater than or equal to the current value.

After these removals, the top of the stack is the nearest smaller value to the left, if it exists.

---

## Algorithm Template

```text
Create an empty stack

For each position from left to right

    Read current value

    While stack is not empty and stack top value >= current value

        Remove stack top

    If stack is empty

        Print 0

    Else

        Print stack top position

    Push current value and position onto the stack
```

---

## Key Idea

Technique:
- Monotonic Stack

Mathematical / Algorithmic Insight:
- Values greater than or equal to the current value cannot be answers for the current position.
- Once removed, such values will never be needed again for future positions behind the current smaller value.
- The stack remains increasing by value from bottom to top.
- Therefore, the top of the stack is always the nearest valid smaller value.

---

## Common Mistakes

- Using `>` instead of `>=`, which incorrectly allows equal values.
- Printing the value instead of the position.
- Forgetting that positions are 1-based.
- Using nested loops, leading to `O(n²)` time.
- Forgetting to push the current value after processing it.

---

## Time Complexity

**O(n)**

**Justification:**

Each element is pushed onto the stack once and popped at most once.

---

## Memory Complexity

**O(n)**

**Justification:**

In the worst case, the stack may store all array elements.

---

## Reference Implementation

See [`nearest_smaller_values.cpp`](../src/nearest_smaller_values.cpp).

---