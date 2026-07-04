# Movie Festival

## Problem

There are `n` movies, each with a starting time and an ending time.

You may watch only one movie at a time, and every selected movie must be watched from beginning to end.

Determine the maximum number of movies that can be watched.

---

## Problem Type

- Sorting
- Greedy
- Interval Scheduling

---

## Core Idea

Sort the movies by their ending times.

Always choose the movie that finishes earliest among all movies that can still be watched. This greedy strategy leaves the maximum amount of time available for future movies.

---

## Algorithm Template

```text
Read all movies

Sort movies by ending time

currentEndingTime = 0

watchedMovies = 0

For each movie

    If movie starts after or exactly when the previous selected movie ends

        Select the movie

        Update currentEndingTime

Print watchedMovies
```

---

## Key Idea

Technique:
- Sorting
- Greedy
- Interval Scheduling

Mathematical / Algorithmic Insight:
- Choosing the movie with the earliest finishing time always leaves the greatest amount of remaining time for future movies.
- This greedy choice is optimal and forms the classical interval scheduling algorithm.
- Every movie is considered exactly once after sorting.

---

## Common Mistakes

- Sorting by starting time instead of ending time.
- Choosing the shortest movie instead of the earliest finishing movie.
- Rejecting movies that start exactly when the previous movie ends (`start == currentEndingTime`).
- Using a quadratic solution that compares every pair of movies.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting the movies requires `O(n log n)`. The subsequent scan processes every movie once.

---

## Memory Complexity

**O(n)**

**Justification:**

The list of movies is stored in a vector. The algorithm itself uses only constant extra memory besides the input storage.

---

## Reference Implementation

See [`movie_festival.cpp`](../src/movie_festival.cpp).

---