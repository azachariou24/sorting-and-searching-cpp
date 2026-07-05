<div align="center">

# CSES Sorting and Searching in C++

### Optimal solutions with algorithmic insights and complexity analysis

**C++17 • Algorithms • Sorting • Searching • Competitive Programming**

</div>

---

## Overview

This repository contains my solutions to the **CSES Sorting and Searching** problem set, implemented in modern **C++17**.

Rather than serving as a simple collection of accepted solutions, the repository is designed as a structured study of classical algorithmic techniques used in competitive programming and algorithm design.

Each solution emphasizes the reasoning behind the algorithm, the key observations that lead to an optimal approach, and a complete complexity analysis. The accompanying documentation explains not only how the algorithm works, but also why it is correct and efficient.

The repository covers a broad range of fundamental techniques, including greedy algorithms, sorting, binary search, two pointers, sliding windows, prefix sums, interval scheduling, monotonic data structures, ordered sets, Fenwick Trees, and mathematical observations.

Its primary objective is to build a solid foundation in algorithmic problem solving while producing clean, well-documented implementations suitable for competitive programming, technical interviews, and computer science education.

---

## Repository Philosophy

The goal of this repository is not simply to collect accepted solutions, but to document a systematic approach to algorithmic problem solving.

Each problem is treated as an opportunity to understand the underlying technique, identify the key observation, and develop an optimal solution supported by clear mathematical reasoning and complexity analysis.

Rather than focusing only on implementation, every solution aims to explain the complete problem-solving process, from the initial idea to the final algorithm.

To maintain consistency throughout the repository, every problem follows the same structured workflow:

- Understand the problem statement
- Identify the core algorithmic insight
- Design an optimal algorithm
- Explain the mathematical or algorithmic reasoning
- Analyze time and memory complexity
- Produce a clean, readable, and efficient C++17 implementation
- Document the solution in a dedicated Markdown summary

---

## Features

- Clean and optimized **C++17** implementations
- Solutions accepted by the **CSES Problem Set**
- Consistent coding style across all solutions
- Detailed Markdown summary for every solved problem
- Clear explanation of the core algorithmic idea
- Step-by-step algorithm template
- Mathematical and algorithmic insights
- Time and memory complexity analysis
- Common mistakes and implementation pitfalls
- Professional repository organization
- Educational documentation suitable for self-study
- Incrementally expanding collection of Sorting and Searching algorithms

---

## Study Methodology

Every problem in this repository follows the same structured workflow to ensure consistency, readability, and a deeper understanding of the underlying algorithm.

### 1. Problem Understanding

Carefully analyze the problem statement and identify the exact computational task.

### 2. Core Idea

Determine the key observation or algorithmic technique that leads to an optimal solution.

### 3. Algorithm Design

Design the complete algorithm before writing any code.

### 4. Correctness Insight

Explain why the algorithm is correct using mathematical reasoning, greedy arguments, invariants, or structural observations whenever appropriate.

### 5. Complexity Analysis

Analyze both the time complexity and the memory complexity of the solution.

### 6. Implementation

Develop a clean, efficient, and readable C++17 implementation following a consistent coding style.

### 7. Documentation

Document every solution in a dedicated Markdown summary containing the algorithmic intuition, implementation strategy, common mistakes, and complexity analysis.

---

## Techniques Covered

The repository covers a broad collection of classical algorithmic techniques commonly used in competitive programming and algorithm design, including:

### Sorting and Searching

- Sorting
- Binary Search
- Binary Search on Answer
- Coordinate Compression

### Greedy Algorithms

- Greedy Scheduling
- Interval Scheduling
- Mathematical Greedy
- Greedy Pairing

### Two-Pointer Techniques

- Two Pointers
- Sliding Window
- Fixed-Length Window
- Variable-Length Window

### Prefix Sum Techniques

- Prefix Sums
- Prefix Sums with Frequency Maps
- Prefix Sums with Modular Arithmetic

### Data Structures

- Ordered Sets (`set`)
- Ordered Multisets (`multiset`)
- Priority Queues
- Monotonic Stack
- Fenwick Tree (Binary Indexed Tree)
- Frequency Maps

### Mathematical Techniques

- Mathematical Observations
- Median Optimization
- Counting Arguments
- Modular Arithmetic

### General Algorithm Design

- Sweep Line
- Range Queries
- Interval Processing
- Order Statistics

---

## Repository Statistics

**Language**

- ISO C++17

**Repository Organization**

- One C++ source file for every solved problem
- One dedicated Markdown summary for every solved problem
- Consistent project structure and coding style

**Every Solution Includes**

- Problem overview
- Core Idea
- Algorithm Template
- Key Idea
- Mathematical / Algorithmic Insight
- Common Mistakes
- Time Complexity
- Memory Complexity
- Reference Implementation

---

## Learning Outcomes

Working through this collection of problems provides practical experience with:

- Greedy algorithm design
- Binary Search on Answer
- Sliding Window techniques
- Two Pointers
- Prefix Sum methods
- Interval Scheduling
- Ordered Sets and Multisets
- Fenwick Trees (Binary Indexed Trees)
- Monotonic Data Structures
- Efficient algorithm design and implementation in C++17

---

## Repository Structure

```text
sorting-and-searching-cpp/
│
├── src/
│   ├── apartments.cpp
│   ├── array_division.cpp
│   ├── concert_tickets.cpp
│   ├── ...
│   └── traffic_lights.cpp
│
├── summaries/
│   ├── apartments.md
│   ├── array_division.md
│   ├── concert_tickets.md
│   ├── ...
│   └── traffic_lights.md
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## Running a Solution

### Requirements

- A C++17 compatible compiler (GCC, Clang, or MSVC)

### Compile

```bash
g++ -std=c++17 -O2 -Wall src/apartments.cpp -o apartments
```

### Run

```bash
./apartments
```

The same procedure applies to every solution in the repository by replacing the source file name with the desired problem.

---

## Problem Summaries

Every solved problem is accompanied by a dedicated Markdown summary explaining the underlying algorithm, mathematical intuition, implementation strategy, and complexity analysis.

Each summary follows the same structure and includes:

- Problem
- Problem Type
- Core Idea
- Algorithm Template
- Key Idea
- Mathematical / Algorithmic Insight
- Common Mistakes
- Time Complexity
- Memory Complexity
- Reference Implementation

The table below provides quick access to every solved problem and its corresponding summary.

| Problem | Technique | Summary |
|----------|-----------|---------|
| Distinct Numbers | Sorting | [View](summaries/distinct_numbers.md) |
| Apartments | Sorting + Two Pointers | [View](summaries/apartments.md) |
| Ferris Wheel | Greedy + Two Pointers | [View](summaries/ferris_wheel.md) |
| Concert Tickets | Ordered Multiset | [View](summaries/concert_tickets.md) |
| Restaurant Customers | Sweep Line | [View](summaries/restaurant_customers.md) |
| Movie Festival | Greedy Interval Scheduling | [View](summaries/movie_festival.md) |
| Sum of Two Values | Sorting + Two Pointers | [View](summaries/sum_of_two_values.md) |
| Maximum Subarray Sum | Kadane's Algorithm | [View](summaries/maximum_subarray_sum.md) |
| Stick Lengths | Median Optimization | [View](summaries/stick_lengths.md) |
| Missing Coin Sum | Greedy | [View](summaries/missing_coin_sum.md) |
| Collecting Numbers | Position Array | [View](summaries/collecting_numbers.md) |
| Collecting Numbers II | Position Updates | [View](summaries/collecting_numbers_II.md) |
| Playlist | Sliding Window | [View](summaries/playlist.md) |
| Towers | Ordered Multiset | [View](summaries/towers.md) |
| Traffic Lights | Ordered Set + Multiset | [View](summaries/traffic_lights.md) |
| Josephus Problem I | Order Statistics | [View](summaries/josephus_problem_I.md) |
| Josephus Problem II | Order Statistics Tree | [View](summaries/josephus_problem_II.md) |
| Nested Ranges Check | Sorting | [View](summaries/nested_ranges_check.md) |
| Nested Ranges Count | Fenwick Tree | [View](summaries/nested_ranges_count.md) |
| Room Allocation | Priority Queue | [View](summaries/room_allocation.md) |
| Factory Machines | Binary Search on Answer | [View](summaries/factory_machines.md) |
| Tasks and Deadlines | Greedy Scheduling | [View](summaries/tasks_and_deadlines.md) |
| Reading Books | Mathematical Observation | [View](summaries/reading_books.md) |
| Sum of Three Values | Sorting + Two Pointers | [View](summaries/sum_of_three_values.md) |
| Sum of Four Values | Pair Sums | [View](summaries/sum_of_four_values.md) |
| Nearest Smaller Values | Monotonic Stack | [View](summaries/nearest_smaller_values.md) |
| Subarray Sums I | Sliding Window | [View](summaries/subarray_sums_I.md) |
| Subarray Sums II | Prefix Sums + Frequency Map | [View](summaries/subarray_sums_II.md) |
| Subarray Divisibility | Prefix Sums + Modular Arithmetic | [View](summaries/subarray_divisibility.md) |
| Subarray Distinct Values | Sliding Window + Frequency Map | [View](summaries/subarray_distinct_values.md) |
| Array Division | Binary Search on Answer | [View](summaries/array_division.md) |
| Movie Festival II | Greedy + Ordered Multiset | [View](summaries/movie_festival_II.md) |
| Maximum Subarray Sum II | Prefix Sums + Multiset | [View](summaries/maximum_subarray_sum_II.md) |

---

## References

- **CSES Problem Set** — https://cses.fi/problemset/
- Steven Halim et al., *Competitive Programming*
- Thomas H. Cormen et al., *Introduction to Algorithms (CLRS)*
- Donald E. Knuth, *The Art of Computer Programming*

---

## License

This project is licensed under the **MIT License**.

---

<div align="center">

Maintained by **Anastasis Zachariou**

</div>