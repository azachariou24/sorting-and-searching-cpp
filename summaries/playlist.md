# Playlist

## Problem

Given a playlist of `n` songs, determine the length of the longest contiguous sequence in which every song appears at most once.

---

## Problem Type

- Sliding Window
- Ordered Map
- Two Pointers

---

## Core Idea

Maintain a sliding window that always contains only unique songs.

As the right boundary expands, if the current song already exists inside the current window, move the left boundary just after its previous occurrence.

The maximum window length encountered during the scan is the answer.

---

## Algorithm Template

```text
Read the playlist

left = 0

answer = 0

For each song from left to right

    If the song already appears inside the current window

        Move left after its previous occurrence

    Update the song's latest position

    Update the maximum window length

Print answer
```

---

## Key Idea

Technique:
- Sliding Window
- Ordered Map

Mathematical / Algorithmic Insight:
- The current window always contains distinct songs.
- Whenever a duplicate song appears, only the left boundary must move.
- The left boundary never moves backwards, making the algorithm efficient.
- The answer is the largest window size observed during the scan.

---

## Common Mistakes

- Restarting the entire window after finding a duplicate.
- Moving the left boundary backwards.
- Forgetting to update the latest occurrence of each song.
- Using a quadratic solution by checking every subarray.

---

## Time Complexity

**O(n log n)**

**Justification:**

Each song is processed once. Every insertion, lookup, and update in the ordered map takes `O(log n)` time.

---

## Memory Complexity

**O(n)**

**Justification:**

The ordered map stores the latest position of each distinct song.

---

## Reference Implementation

See [`playlist.cpp`](../src/playlist.cpp).

---