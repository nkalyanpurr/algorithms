# Fuzzy sorting of intervals

- [Fuzzy sorting of intervals](#fuzzy-sorting-of-intervals)
  - [Introduction](#introduction)
  - [Time Complexity Analysis](#time-complexity-analysis)
    - [Fuzzy sort](#fuzzy-sort)
    - [Randomized Quicksort](#randomized-quicksort)
  - [Results](#results)
    - [Fuzzy sort](#fuzzy-sort-1)
    - [Randomized quicksort](#randomized-quicksort-1)
  - [References](#references)

## Introduction

Consider a sorting problem in which the numbers are not known exactly. Instead, for each number, we know an interval on the real line to which it belongs. That is, we are given `n` closed intervals of the form `[ai, bi]`, where `ai ≤ bi`. The goal is to fuzzy-sort these intervals, i.e., produce a permutation `〈i1, i2,..., in〉` of the intervals such that there exist `cj` in each `[aj,bj]`, satisfying `c1 ≤ c2 ≤ ··· ≤ cn`.

This is a rather popular problem with multiple solutions freely available on the internet - the most helpful I've found are available [here](http://courses.csail.mit.edu/6.046/spring04/handouts/ps2-sol.pdf) and [here](http://alumni.media.mit.edu/~dlanman/courses/cs157/HW3.pdf).

## Time Complexity Analysis

### Fuzzy sort

When input instances are disjoint, the worst case time complexity is `O(nlogn)`.
When input instances overlap at one point, then the worst case time complexity reduces to less than `O(nlogn)` which is `O(n)`.

### Randomized Quicksort

Worst case time complexity of quicksort is `O(nlogn)`. 
However, if all input instances are the same numbers, then the worst case time complexity of randomized quicksort tends to be `O(n^2)`.

## Results

When the execution time (in nanoseconds) was compared for fuzzy sorting and randomized quicksort, it was observed that for the same input size, fuzzy sort works faster than randomized quicksort (provided input instances are not disjoint).

### Fuzzy sort

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


### Randomized quicksort

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
## References

- [1] For time complexity analysis
https://stackoverflow.com/questions/45779963/randomized-quick-sort-worst-case-time-complexity
- [2] Randomized Quicksort
https://www.geeksforgeeks.org/quicksort-using-random-pivoting/
