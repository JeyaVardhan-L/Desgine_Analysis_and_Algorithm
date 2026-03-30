# N-Queens Problem

## Problem Statement
Place `N` chess queens on an `N×N` chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal.

## Approach: Backtracking
We place queens one by one in different columns, starting from the leftmost column. When placing a queen, we check for clashes with already placed queens. If we find a safe row in the current column, we place the queen and recursively check for the next column. If no safe row exists, we backtrack and change the position of the previously placed queen.

## Complexity
- **Time Complexity:** `O(N!)`
- **Space Complexity:** `O(N)` for storing the positions and the recursion stack.