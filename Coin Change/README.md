# Coin Change Problem

- [Coin Change Problem](#coin-change-problem)
  - [Introduction](#introduction)
  - [Description](#description)
  - [Results](#results)

## Introduction

**Objective:** Given a set of coins and amount, Write an algorithm to find out how many ways we can make the change of the amount using the coins given.

The repository contains a `coinChange.cpp` file that implements a greedy algorithm takes `O(nk)` for any kind of coin set denomination, where `k` is the number of different coins in a particular set. 

## Description

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

## Results

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