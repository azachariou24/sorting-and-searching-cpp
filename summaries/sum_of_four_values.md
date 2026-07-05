# Sum of Four Values

## Problem

Given an array of `n` integers, find four values at distinct positions whose sum is equal to `x`.

Print the original positions of these four values.

If there are several valid answers, any one of them may be printed. If no such quadruple exists, print `IMPOSSIBLE`.

---

## Problem Type

- Hashing / Map
- Pair Sums
- Four Sum

---

## Core Idea

Split the target equation into two pair sums:

```text
a + b + c + d = x
```

This can be rewritten as:

```text
(a + b) + (c + d) = x
```

For each candidate second pair, look for a previously stored first pair whose sum completes the target.

By storing only pairs that end before the current second pair begins, all four indices are guaranteed to be distinct.

---

## Algorithm Template

```text
Read n and x

Read the array

previousPairs = empty map

For secondPairStart from 0 to n - 1

    For secondPairEnd from secondPairStart + 1 to n - 1

        neededSum = x - values[secondPairStart] - values[secondPairEnd]

        If neededSum exists in previousPairs

            Print the two stored indices and the current two indices

            Stop

    For firstPairStart from 0 to secondPairStart - 1

        Store sum of values[firstPairStart] + values[secondPairStart]
```

---

## Key Idea

Technique:
- Pair Sums
- Map Lookup
- Index Separation

Mathematical / Algorithmic Insight:
- A four-value sum can be decomposed into two two-value sums.
- If one pair has sum `s`, the other pair must have sum `x - s`.
- Storing previous pair sums allows each lookup to be done efficiently.
- Storing only pairs from earlier indices ensures that the two pairs do not share positions.

---

## Common Mistakes

- Trying all quadruples, which is too slow.
- Forgetting that all four positions must be distinct.
- Storing pairs that may overlap with the current pair.
- Printing zero-based indices instead of one-based indices.
- Using `int` for sums when values can be up to `10^9`.

---

## Time Complexity

**O(n² log n)**

**Justification:**

There are `O(n²)` pairs. Each map lookup and insertion takes `O(log n)` time.

---

## Memory Complexity

**O(n²)**

**Justification:**

In the worst case, the map may store a quadratic number of pair sums.

---

## Reference Implementation

See [`sum_of_four_values.cpp`](../src/sum_of_four_values.cpp).

---