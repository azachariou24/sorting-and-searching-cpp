# Reading Books

## Problem

Two people must each read all `n` books.

Each book has a reading time.

The same book cannot be read by both people simultaneously, but different books may be read in parallel.

Determine the minimum total time until both people finish reading every book.

---

## Problem Type

- Greedy
- Mathematical Observation

---

## Core Idea

Two lower bounds always exist:

- The total reading time of all books.
- Twice the reading time of the longest book, since both people must read it separately.

The minimum possible completion time is the larger of these two values.

---

## Algorithm Template

```text
Read all book times

Compute

    total reading time

    longest book

Answer = max(total reading time, 2 × longest book)

Print answer
```

---

## Key Idea

Technique:
- Greedy
- Mathematical Observation

Mathematical / Algorithmic Insight:
- At least `sum(times)` time is required because one person must read all books.
- The longest book must be read twice, once by each person, and these readings cannot overlap.
- Therefore, at least `2 × longestBook` time is also required.
- A schedule achieving the larger of these two bounds always exists.

---

## Common Mistakes

- Trying to simulate the reading schedule.
- Assuming both people can read the same book simultaneously.
- Forgetting that every book must be read by both people.
- Using `int` instead of `long long`.

---

## Time Complexity

**O(n)**

**Justification:**

The books are scanned once to compute the total reading time and the longest book.

---

## Memory Complexity

**O(1)**

**Justification:**

Only the running sum and the maximum reading time are stored.

---

## Reference Implementation

See [`reading_books.cpp`](../src/reading_books.cpp).

---