# Restaurant Customers

## Problem

Given the arrival and leaving times of `n` customers in a restaurant, determine the maximum number of customers that were inside the restaurant at the same time.

All arrival and leaving times are distinct.

---

## Problem Type

- Sorting
- Sweep Line
- Events

---

## Core Idea

Convert each customer into two events:

- arrival event: `+1`
- leaving event: `-1`

After sorting all events by time, scan them in chronological order and maintain the current number of customers inside the restaurant.

The maximum value reached during the scan is the answer.

---

## Algorithm Template

```text
Create an empty list of events

For each customer

    Add arrival event with value +1

    Add leaving event with value -1

Sort events by time

current = 0

answer = 0

For each event in sorted order

    Add event value to current

    Update answer with maximum of answer and current

Print answer
```

---

## Key Idea

Technique:
- Sorting
- Sweep Line

Mathematical / Algorithmic Insight:
- The number of customers inside the restaurant changes only at arrival or leaving times.
- Therefore, it is sufficient to process only these event times.
- Arrival events increase the active count, while leaving events decrease it.
- The maximum active count during the sweep is the maximum number of simultaneous customers.

---

## Common Mistakes

- Checking every possible time value, which is impossible because times can be as large as `10^9`.
- Forgetting to add both arrival and leaving events.
- Updating the answer before processing an arrival event.
- Treating the intervals incorrectly when arrival and leaving times overlap.
- Using nested loops to compare every customer interval with every other interval.

---

## Time Complexity

**O(n log n)**

**Justification:**

There are `2n` events. Sorting them takes `O(n log n)`, and the sweep itself is linear.

---

## Memory Complexity

**O(n)**

**Justification:**

The algorithm stores two events for each customer, requiring linear memory.

---

## Reference Implementation

See [`restaurant_customers.cpp`](../src/restaurant_customers.cpp).

---