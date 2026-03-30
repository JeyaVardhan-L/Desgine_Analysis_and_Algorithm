# Depth-First Search (DFS)

## Problem Statement
Traverse or search tree or graph data structures. The algorithm starts at a root node and explores as far as possible along each branch before backtracking.

## Approach
DFS uses a stack data structure (or recursion, which uses the call stack). It marks the current vertex as visited, then recursively visits all its unvisited adjacent vertices.

## Complexity
- **Time Complexity:** `O(V + E)` where `V` is the number of vertices and `E` is the number of edges.
- **Space Complexity:** `O(V)` to store the visited array and recursion stack.

