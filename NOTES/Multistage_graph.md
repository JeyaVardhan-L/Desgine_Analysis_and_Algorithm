Multistage Graph Shortest Path

A Multistage Graph is a directed, weighted graph where the vertices are divided into distinct "stages".

The Rules:

You start at a source node (Stage 1) and want to reach a destination node (the final Stage).

Edges only ever point forward from one stage to the immediate next stage. You cannot skip stages, and you cannot go backward.

The Strategy (Dynamic Programming):
Instead of blindly moving forward, we solve this by working backward from the destination to the source.

The cost to go from the destination to the destination is 0.

For the nodes in the second-to-last stage, we look at the edge weights connecting them to the destination.

For nodes in earlier stages, we calculate the cost by looking at all possible next steps. The formula is:
Cost of current node = Minimum of (Edge weight to next node + Cost from next node to destination).

By the time we work our way back to the source node, we will have found the absolute shortest path.

Complexity:

Time Complexity: O(V + E) - Where V is the number of vertices and E is the number of edges. In a dense adjacency matrix, this looks like O(V^2).

Space Complexity: O(V) - We need a couple of 1D arrays to store the costs and the path choices.