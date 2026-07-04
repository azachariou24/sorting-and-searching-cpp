# Concert Tickets

## Problem

There are `n` concert tickets, each with a certain price.

Then `m` customers arrive one by one. Each customer announces the maximum price they are willing to pay for a ticket.

For each customer, assign the most expensive available ticket whose price does not exceed the customer's maximum price.

After a ticket is sold, it cannot be purchased again.

If no suitable ticket exists, print `-1`.

---

## Problem Type

- Sorting
- Ordered Set
- Binary Search
- Greedy

---

## Core Idea

For each customer, we need to efficiently find the greatest ticket price that is less than or equal to the customer's maximum price.

Since tickets may have duplicate prices and sold tickets must be removed, a `multiset` is a natural choice.

---

## Algorithm Template

```text
Insert all ticket prices into a multiset

For each customer

    Read maximum price

    Find first ticket greater than maximum price using upper_bound

    If this is the beginning of the multiset

        No valid ticket exists

        Print -1

    Else

        Move one step back

        Print this ticket price

        Remove this ticket from the multiset
```

---

## Key Idea

Technique:
- Ordered Multiset
- Binary Search
- Greedy Selection

Mathematical / Algorithmic Insight:
- The best ticket for a customer is the largest available ticket price that does not exceed their maximum price.
- `upper_bound(x)` gives the first value strictly greater than `x`.
- Therefore, the previous element is the greatest value less than or equal to `x`.
- Removing the chosen ticket guarantees that each ticket is sold at most once.

---

## Common Mistakes

- Using `set` instead of `multiset`, which incorrectly removes duplicate ticket prices.
- Using `lower_bound` without handling equality and predecessor cases carefully.
- Forgetting to remove the sold ticket.
- Sorting tickets once but not supporting efficient removal.
- Giving customers tickets in sorted order instead of preserving the arrival order.

---

## Time Complexity

**O((n + m) log n)**

**Justification:**

Inserting `n` tickets into the multiset takes `O(n log n)`. For each of the `m` customers, both `upper_bound` and `erase` take logarithmic time.

---

## Memory Complexity

**O(n)**

**Justification:**

The multiset stores all currently available tickets. No additional large data structures are required.

---

## Reference Implementation

See [`concert_tickets.cpp`](../src/concert_tickets.cpp).

---