# Tasks and Deadlines

## Problem

There are `n` tasks. Each task has a duration and a deadline.

Tasks must be processed one after another in some order. If a task has deadline `d` and finishes at time `f`, its reward is `d - f`.

All tasks must be processed, even if some rewards are negative.

Determine the maximum possible total reward.

---

## Problem Type

- Sorting
- Greedy
- Scheduling

---

## Core Idea

The total reward is:

```text
sum(deadlines) - sum(finishing times)
```

The sum of deadlines is fixed, regardless of the processing order.

Therefore, maximizing total reward is equivalent to minimizing the sum of finishing times.

This is achieved by processing tasks in increasing order of duration.

---

## Algorithm Template

```text
Read all tasks

Sort tasks by duration ascending

currentTime = 0

reward = 0

For each task

    currentTime += duration

    reward += deadline - currentTime

Print reward
```

---

## Key Idea

Technique:
- Greedy
- Shortest Processing Time First

Mathematical / Algorithmic Insight:
- Deadlines contribute a fixed total value to the reward.
- The only part affected by the task order is the sum of finishing times.
- Placing shorter tasks earlier minimizes the accumulated finishing times.
- This is the classical shortest-processing-time-first scheduling rule.

---

## Common Mistakes

- Sorting by deadline instead of duration.
- Trying to maximize each task reward locally.
- Forgetting that all tasks must be processed.
- Using `int` for the reward, which may overflow.
- Assuming negative rewards can be skipped.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting the tasks by duration takes `O(n log n)`. The final scan is linear.

---

## Memory Complexity

**O(n)**

**Justification:**

The tasks are stored in a vector.

---

## Reference Implementation

See [`tasks_and_deadlines.cpp`](../src/tasks_and_deadlines.cpp).

---