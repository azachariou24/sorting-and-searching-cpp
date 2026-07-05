# Factory Machines

## Problem

A factory has `n` machines, and the goal is to produce at least `t` products.

Each machine has a production time `k_i`, meaning it takes `k_i` seconds to make one product.

All machines can work simultaneously.

Determine the minimum time needed to produce at least `t` products.

---

## Problem Type

- Binary Search
- Binary Search on Answer
- Greedy Feasibility Check

---

## Core Idea

Instead of simulating machine schedules, binary search the answer.

For a fixed time `T`, the number of products produced is:

```text
T / k_1 + T / k_2 + ... + T / k_n
```

If this value is at least `t`, then `T` is enough time. Otherwise, more time is needed.

---

## Algorithm Template

```text
Read machines and target products

left = 1

right = fastest machine time * t

answer = right

While left <= right

    middle = candidate time

    Count how many products can be made in middle seconds

    If products >= t

        Save middle as a possible answer

        Search smaller times

    Else

        Search larger times

Print answer
```

---

## Key Idea

Technique:
- Binary Search on Answer
- Feasibility Check

Mathematical / Algorithmic Insight:
- If it is possible to produce `t` products in time `T`, then it is also possible in any time greater than `T`.
- This monotonic property allows binary search.
- The feasibility check computes how many products all machines can produce within a candidate time.
- The smallest feasible time is the answer.

---

## Common Mistakes

- Trying to simulate the production process directly.
- Using `int` for time or product counts, which can overflow.
- Setting the upper bound too small.
- Forgetting that all machines work simultaneously.
- Not stopping the product count early after reaching `t`.

---

## Time Complexity

**O(n log M)**

**Justification:**

For each binary search step, all machines may be checked once. The search range is over time values up to `M = min(k_i) * t`.

---

## Memory Complexity

**O(n)**

**Justification:**

The machine production times are stored in a vector.

---

## Reference Implementation

See [`factory_machines.cpp`](../src/factory_machines.cpp).

---