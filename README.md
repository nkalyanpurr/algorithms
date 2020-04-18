# Algorithm and Data structures

- [Algorithm and Data structures](#algorithm-and-data-structures)
  - [Rudimentary algorithms for sorting and searching](#rudimentary-algorithms-for-sorting-and-searching)
  - [Coin Change Problem](#coin-change-problem)
    - [Introduction](#introduction)
    - [Description](#description)
    - [Results](#results)
  - [Fuzzy sorting of intervals](#fuzzy-sorting-of-intervals)
    - [Introduction](#introduction-1)
    - [Time Complexity Analysis](#time-complexity-analysis)
      - [Fuzzy sort](#fuzzy-sort)
      - [Randomized Quicksort](#randomized-quicksort)
    - [Results](#results-1)
      - [Fuzzy sort](#fuzzy-sort-1)
      - [Randomized quicksort](#randomized-quicksort-1)
    - [References](#references)
  - [Maximum Subarray problem](#maximum-subarray-problem)
    - [Description](#description-1)

## Rudimentary algorithms for sorting and searching

The following repository contains an `alg` class that has Java implementations for the following algorithms -

- **Sorting**
  - Bubble sort
  - Insertion sort
  - Merge sort
  - Selection sort
- **Searching**
  - Binary search
  - Linear search

## Coin Change Problem


### Introduction

**Objective:** Given a set of coins and amount, Write an algorithm to find out how many ways we can make the change of the amount using the coins given.

The repository contains a `coinChange.cpp` file that implements a greedy algorithm takes `O(nk)` for any kind of coin set denomination, where `k` is the number of different coins in a particular set. 

### Description

- If `n < 5`, use `n` pennies. 
- If `5 ≤ n < 10`, use `1` nickel and `n − 5` pennies 
- If `10 ≤ n < 25`, use `n / 10` dimes, and then the rest will be either pennies or nickels. 
- If `25 ≤ n`, use `n / 25` quarters, and then one of the 3 previous cases. 
 
What the greedy algorithm does is to always use the greatest value coins for the existing amount and to use as many of those coins as possible without exceeding the existing amount. After deducting this sum from the existing amount, the remainder is used as the new existing amount and repeat the process.

To prove that this algorithm yields an optimal solution, firstly make sure that the greedy-choice property holds, i.e to get an optimal solution which is making change for `n` cents which contains `c`, where `c` is the largest coin (`c <= n`).  If `c` is equal to `n` cents, then `c` will be the solution and the computations stop to look for other coins. Otherwise, the optimal solution doesn’t include a coin of value `c`.
- If `1 ≤ n < 5`, then `c = 1`. A solution may consist only of pennies, and so it must contain the greedy choice. 
- If `5 ≤ n < 10`, then `c = 5`. A solution may consist of a nickel and the rest will be pennies. In case there were just pennies, then the number of coins will increase thus making it less optimal. 
- If `10 ≤ n < 25`, then `c = 10`. By supposition, this optimal solution does not contain a dime, and so it contains only nickels and pennies. Some subset of the nickels and pennies in this solution adds up to `10` cents, and so we can replace these nickels and pennies by a dime to give a solution with fewer coins. 
- If `25 ≤ n`, then `c = 25`. An optimal solution consists of a quarter. But in case there are online dimes, nickels and pennies that adds up to `25` cents, then it can be replaced by a quarter to reduce the number of coins thus making it optimal. 

### Results

For `amount = 99` -

```
Amount: 99 
coin: 25 quarter 
coin: 25 quarter 
coin: 25 quarter 
coin: 10 dime 
coin: 10 dime 
coin: 1 penny 
coin: 1 penny 
coin: 1 penny 
coin: 1 penny 
Total number of coins: 9
```

For `amount = 75` -

```
Amount: 75 
coin: 25 quarter 
coin: 25 quarter 
coin: 25 quarter 
Total number of coins: 3
```

## Fuzzy sorting of intervals

- [Algorithm and Data structures](#algorithm-and-data-structures)
  - [Rudimentary algorithms for sorting and searching](#rudimentary-algorithms-for-sorting-and-searching)
  - [Coin Change Problem](#coin-change-problem)
    - [Introduction](#introduction)
    - [Description](#description)
    - [Results](#results)
  - [Fuzzy sorting of intervals](#fuzzy-sorting-of-intervals)
    - [Introduction](#introduction-1)
    - [Time Complexity Analysis](#time-complexity-analysis)
      - [Fuzzy sort](#fuzzy-sort)
      - [Randomized Quicksort](#randomized-quicksort)
    - [Results](#results-1)
      - [Fuzzy sort](#fuzzy-sort-1)
      - [Randomized quicksort](#randomized-quicksort-1)
    - [References](#references)
  - [Maximum Subarray problem](#maximum-subarray-problem)
    - [Description](#description-1)

### Introduction

Consider a sorting problem in which the numbers are not known exactly. Instead, for each number, we know an interval on the real line to which it belongs. That is, we are given `n` closed intervals of the form `[ai, bi]`, where `ai ≤ bi`. The goal is to fuzzy-sort these intervals, i.e., produce a permutation `〈i1, i2,..., in〉` of the intervals such that there exist `cj` in each `[aj,bj]`, satisfying `c1 ≤ c2 ≤ ··· ≤ cn`.

This is a rather popular problem with multiple solutions freely available on the internet - the most helpful I've found are available [here](http://courses.csail.mit.edu/6.046/spring04/handouts/ps2-sol.pdf) and [here](http://alumni.media.mit.edu/~dlanman/courses/cs157/HW3.pdf).

### Time Complexity Analysis

#### Fuzzy sort

When input instances are disjoint, the worst case time complexity is `O(nlogn)`.
When input instances overlap at one point, then the worst case time complexity reduces to less than `O(nlogn)` which is `O(n)`.

#### Randomized Quicksort

Worst case time complexity of quicksort is `O(nlogn)`. 
However, if all input instances are the same numbers, then the worst case time complexity of randomized quicksort tends to be `O(n^2)`.

### Results

When the execution time (in nanoseconds) was compared for fuzzy sorting and randomized quicksort, it was observed that for the same input size, fuzzy sort works faster than randomized quicksort (provided input instances are not disjoint).

#### Fuzzy sort

- Test case 1
  - Input -
    ```
    [5, 7]
    [1, 3]
    [4, 6]
    [8, 10]
    ``` 
  - Output -
    ```
    [1, 3]
    [4, 6]
    [5, 7]
    [8, 10]
    ``` 
- Test case 2
  - Input -
    ```
    [6, 7]
    [9, 11]
    [13, 14]
    [3, 7]
    [11, 15]
    [13, 14]
    [12, 14]
    [14, 15]
    [9, 15]
    [5, 7]
    [7, 9]
    [1, 5]
    [1, 9]
    [6, 10]
    ```
  - Output -
    ```
    [1, 5]
    [6, 10]
    [5, 7]
    [7, 9]
    [6, 7]
    [1, 9]
    [3, 7]
    [9, 11]
    [12, 14]
    [13, 14]
    [14, 15]
    [11, 15]
    [13, 14]
    [9, 15]
    ```


#### Randomized quicksort

- Test case 1
  - Input -
    ```
    [5, 7]
    [1, 3]
    [4, 6]
    [8, 10]
    ``` 
  - Output -
    ```
    [1, 3]
    [4, 6]
    [5, 7]
    [8, 10]
    ``` 
- Test case 2
  - Input -
    ```
    [6, 7]
    [9, 11]
    [13, 14]
    [3, 7]
    [11, 15]
    [13, 14]
    [12, 14]
    [14, 15]
    [9, 15]
    [5, 7]
    [7, 9]
    [1, 5]
    [1, 9]
    [6, 10]
    ```
  - Output -
    ```
    [1, 5]
    [6, 10]
    [5, 7]
    [7, 9]
    [6, 7]
    [1, 9]
    [3, 7]
    [9, 11]
    [12, 14]
    [13, 14]
    [14, 15]
    [11, 15]
    [13, 14]
    [9, 15]
    ```
### References

- [1] For time complexity analysis
https://stackoverflow.com/questions/45779963/randomized-quick-sort-worst-case-time-complexity
- [2] Randomized Quicksort
https://www.geeksforgeeks.org/quicksort-using-random-pivoting/

## Maximum Subarray problem

This repository consists of an divide and conquer implementation of the maximum subarray problem.

### Description

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```