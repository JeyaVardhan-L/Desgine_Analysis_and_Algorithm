# 0/1 Knapsack Problem

## Problem Statement
Given `N` items, each with a specific weight and a value, and a knapsack with a maximum weight capacity `W`, find the maximum total value that can be accommodated in the knapsack. In the **0/1 Knapsack** problem, you cannot break an item; you must either pick the entire item (1) or leave it (0).

## Approach: Dynamic Programming
A naive approach is to try all possible subsets of items, which takes `O(2^N)` time. To optimize this, we use Dynamic Programming (DP) to store the results of overlapping subproblems.

We build a 2D array `dp[N+1][W+1]` where `dp[i][w]` represents the maximum value that can be obtained using the first `i` items and a maximum weight capacity `w`.

### State Transition:
For each item `i` and weight capacity `w`:
1. If the item's weight is greater than `w`, we cannot include it: 
   `dp[i][w] = dp[i-1][w]`
2. If the item's weight is less than or equal to `w`, we take the maximum of including or excluding it:
   `dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]])`

## Complexity
- **Time Complexity:** `O(N * W)` where `N` is the number of items and `W` is the capacity of the knapsack.
- **Space Complexity:** `O(N * W)` for the DP table. (This can be optimized to `O(W)` using a 1D array).