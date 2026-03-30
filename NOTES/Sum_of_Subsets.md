# Sum of Subsets

## Problem Statement
Given a set of non-negative integers and a value `M`, determine all possible subsets of the given set whose elements sum up to `M`. 

## Approach: Backtracking
We use a backtracking approach to build a state-space tree. We sort the weights and start adding them one by one. If the current sum equals `M`, we print the subset. If the current sum plus the next element exceeds `M`, we backtrack. We also keep track of the remaining sum to prune the tree efficiently.

## Complexity
- **Time Complexity:** `O(2^N)` in the worst case, where `N` is the number of elements.
- **Space Complexity:** `O(N)` for the recursion stack.