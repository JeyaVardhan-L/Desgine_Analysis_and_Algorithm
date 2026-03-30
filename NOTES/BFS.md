# Breadth-First Search (BFS)

## Problem Statement
Traverse or search tree or graph data structures. The algorithm starts at a root node and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.

## Approach
BFS uses a Queue data structure. It starts from a chosen node, marks it as visited, adds it to the queue, and then iteratively dequeues a node, visiting all its unvisited adjacent nodes and enqueuing them.

## Complexity
- **Time Complexity:** `O(V + E)` where `V` is the number of vertices and `E` is the number of edges.
- **Space Complexity:** `O(V)` to store the queue and visited array.
