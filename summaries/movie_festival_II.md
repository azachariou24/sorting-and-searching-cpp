# Movie Festival II

## Problem

There are `n` movies and `k` club members.

Each movie has a starting time and an ending time. Each member can watch only one movie at a time, and every watched movie must be watched from beginning to end.

Determine the maximum total number of movies the club members can watch.

---

## Problem Type

- Sorting
- Greedy
- Ordered Multiset
- Interval Scheduling

---

## Core Idea

Sort movies by ending time.

Maintain the ending time of the last movie watched by each club member.

For each movie, assign it to the available member whose last watched movie ends as late as possible but not after the current movie starts.

If no such member exists, skip the movie.

---

## Algorithm Template

```text
Read all movies

Sort movies by ending time

Initialize k members with end time 0

watchedMovies = 0

For each movie

    Find the first member end time greater than movie start

    If no previous member exists

        Skip the movie

    Else

        Move one step back to get the best available member

        Replace that member's end time with the movie's end time

        Increase watchedMovies

Print watchedMovies
```

---

## Key Idea

Technique:
- Greedy
- Multiset
- Interval Scheduling

Mathematical / Algorithmic Insight:
- Sorting by ending time ensures movies that finish earlier are considered first.
- Assigning a movie to the available member who finished latest preserves earlier available members for future movies.
- If no member has end time at most the movie start time, the movie cannot be watched.
- The multiset allows efficient lookup and update of member availability times.

---

## Common Mistakes

- Sorting by starting time instead of ending time.
- Choosing the earliest available member instead of the latest compatible one.
- Forgetting that a movie starting exactly when another ends is allowed.
- Using `lower_bound` incorrectly instead of `upper_bound`.
- Not handling multiple members with the same end time.

---

## Time Complexity

**O(n log n + n log k)**

**Justification:**

Sorting the movies takes `O(n log n)`. For each movie, one multiset lookup, erase, and insertion are performed, each taking `O(log k)` time.

---

## Memory Complexity

**O(n + k)**

**Justification:**

The algorithm stores all movies and the current availability time of each club member.

---

## Reference Implementation

See [`movie_festival_ii.cpp`](../src/movie_festival_II.cpp).

---