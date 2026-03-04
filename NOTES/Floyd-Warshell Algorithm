The most standard and widely used algorithm for the All-Pairs Shortest Path problem is the Floyd-Warshall Algorithm.
It uses Dynamic Programming to calculate the shortest distances between every pair of vertices in a weighted graph.
It works for both directed and undirected graphs, provided there are no negative weight cycles.

The Floyd-Warshall AlgorithmThe core logic relies on trying every possible node k as an intermediate step between a source node i and a destination node j.

The formula used is:
dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])

How it Works:

1.Initialization: The dist matrix is initialized with the input graph. If there is no edge between nodes, the distance is set to INF. The distance from a node to itself is 0.

2.The Loops (k, i, j):
Outer loop k: Picks the "intermediate" vertex.
Middle loop i: Picks the source vertex.
Inner loop j: Picks the destination vertex.

3.Relaxation: For every pair (i, j), the algorithm checks if going through vertex $k$ is shorter than the current known path. If dist[i][k] + dist[k][j] is less than dist[i][j], we update dist[i][j].

Complexity Analysis
Time Complexity: O(V^3) There are three nested loops, each running V times. This makes it efficient for small to medium-sized graphs (e.g., up to ~400 nodes), but slow for very large graphs.

Space Complexity: O(V^2) We need a 2D array to store the distance matrix.