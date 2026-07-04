# Apartments

## Problem

There are `n` applicants and `m` apartments.

Each applicant has a desired apartment size `x` and will accept any apartment whose size is within the range `[x − k, x + k]`.

Determine the maximum number of applicants who can receive an apartment.

---

## Problem Type

- Sorting
- Greedy
- Two Pointers

---

## Core Idea

Sort both the applicants and the apartment sizes.

Using two pointers, always try to assign the smallest available apartment that satisfies the current applicant. If an apartment is too small, discard it. If it is too large, move to the next applicant. Otherwise, assign the apartment and continue.

---

## Algorithm Template

```text
Read applicants

Read apartments

Sort both arrays

applicant = 0

apartment = 0

matches = 0

While both pointers are valid

    If apartment is too small

        Move apartment pointer

    Else if apartment is too large

        Move applicant pointer

    Else

        Assign apartment

        Increase matches

        Move both pointers

Print matches
```

---

## Key Idea

Technique:
- Sorting
- Greedy
- Two Pointers

Mathematical / Algorithmic Insight:
- Sorting both arrays allows applicants and apartments to be processed in increasing order.
- The smallest apartment that satisfies the current applicant is always the optimal greedy choice.
- Every apartment and every applicant is processed at most once after sorting.

---

## Common Mistakes

- Forgetting to sort both arrays before applying the two-pointer technique.
- Using a quadratic solution by checking every apartment for every applicant.
- Moving the wrong pointer when an apartment is too small or too large.
- Forgetting to move both pointers after a successful assignment.

---

## Time Complexity

**O(n log n + m log m)**

**Justification:**

Sorting both arrays dominates the running time. The two-pointer traversal is linear.

---

## Memory Complexity

**O(n + m)**

**Justification:**

The applicants and apartment sizes are stored in two vectors. The algorithm itself uses only constant extra memory besides the input storage.

---

## Reference Implementation

See [`apartments.cpp`](../src/apartments.cpp).

---