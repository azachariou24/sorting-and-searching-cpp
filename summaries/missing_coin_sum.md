# Missing Coin Sum

## Problem

You have `n` coins with positive integer values.

Using any subset of the coins, determine the smallest positive sum that cannot be created.

---

## Problem Type

- Sorting
- Greedy
- Prefix Reachability

---

## Core Idea

Sort the coins in increasing order.

Maintain the smallest positive sum that cannot currently be created. If all sums from `1` to `smallestMissingSum − 1` can be created, then a coin with value at most `smallestMissingSum` extends this reachable range.

If the next coin is larger than `smallestMissingSum`, then `smallestMissingSum` cannot be created and is the answer.

---

## Algorithm Template

```text
Read all coin values

Sort the coin values

smallestMissingSum = 1

For each coin in sorted order

    If coin > smallestMissingSum

        Stop

    Else

        smallestMissingSum += coin

Print smallestMissingSum
```

---

## Key Idea

Technique:
- Sorting
- Greedy
- Reachable Sum Interval

Mathematical / Algorithmic Insight:
- Suppose all sums from `1` to `s − 1` can currently be created.
- If the next coin has value `c <= s`, then using this coin extends the reachable range to `1` through `s + c − 1`.
- If `c > s`, then no subset of the processed coins can make `s`, and all remaining coins are even larger.
- Therefore, `s` is the smallest missing sum.

---

## Common Mistakes

- Not sorting the coins before applying the greedy argument.
- Trying all subsets, which is impossible for large `n`.
- Initializing the answer to `0` instead of `1`.
- Using `int` for the reachable sum, which may overflow.
- Continuing after finding a gap without realizing the first gap is already the answer.

---

## Time Complexity

**O(n log n)**

**Justification:**

Sorting the coins takes `O(n log n)`. The greedy scan is linear.

---

## Memory Complexity

**O(n)**

**Justification:**

The coin values are stored in a vector of size `n`. The algorithm itself uses only constant extra memory besides the input storage.

---

## Reference Implementation

See [`missing_coin_sum.cpp`](../src/missing_coin_sum.cpp).

---