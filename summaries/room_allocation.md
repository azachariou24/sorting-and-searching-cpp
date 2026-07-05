# Room Allocation

## Problem

There are `n` hotel customers. Each customer has an arrival day and a departure day.

Each customer needs one room. Two customers can use the same room if the departure day of the first customer is strictly earlier than the arrival day of the second customer.

Determine the minimum number of rooms needed and output a valid room assignment for every customer.

---

## Problem Type

- Sorting
- Greedy
- Priority Queue
- Interval Scheduling

---

## Core Idea

Process customers in increasing order of arrival day.

Maintain a priority queue of currently occupied rooms, ordered by the earliest departure day.

For each customer, check whether the room that becomes free the earliest can be reused. If yes, assign that room. Otherwise, create a new room.

---

## Algorithm Template

```text
Read all customers with their original indices

Sort customers by arrival day

occupiedRooms = empty min-heap

totalRooms = 0

For each customer in sorted order

    If the earliest available room has departure < current arrival

        Reuse that room

    Else

        Create a new room

    Store the assigned room using the original customer index

    Push the customer's departure and room number into the heap

Print totalRooms

Print assigned rooms in input order
```

---

## Key Idea

Technique:
- Greedy
- Priority Queue
- Sorting by Arrival Time

Mathematical / Algorithmic Insight:
- To minimize the number of rooms, always try to reuse the room that becomes free the earliest.
- If even the earliest-free room is not available, then no currently occupied room can be reused.
- Therefore, a new room is necessary.
- Sorting by arrival time ensures customers are processed in chronological order.
- Storing original indices allows the final assignment to be printed in input order.

---

## Common Mistakes

- Reusing a room when `departure == arrival`, even though the problem requires `departure < arrival`.
- Forgetting to output room assignments in the original input order.
- Sorting customers but losing their original indices.
- Using a max-heap instead of a min-heap.
- Checking all rooms linearly for each customer, leading to an inefficient solution.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting the customers takes `O(n log n)`. Each customer causes at most one pop and one push in the priority queue, both taking `O(log n)` time.

---

## Memory Complexity

**O(n)**

**Justification:**

The algorithm stores the customers, the room assignments, and the priority queue of occupied rooms.

---

## Reference Implementation

See [`room_allocation.cpp`](../src/room_allocation.cpp).

---