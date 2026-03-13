# Floyd-Warshall Algorithm

The Floyd-Warshall algorithm is a brilliant example of **Dynamic Programming**. It is used to find the shortest paths between ALL pairs of vertices in a weighted graph. This means that after running it once, you instantly know the absolute fastest route from any node to any other node.

It works by systematically checking if a path between two nodes (i and j) can be made shorter by routing it through an intermediate node (k). 

### Complexity Analysis
* **Time Complexity:** O(V^3) where V is the number of vertices. The algorithm uses three nested loops, each iterating V times. Because of this cubic time complexity, it is incredibly efficient for small to medium-sized dense graphs, but becomes too slow for massive networks with millions of nodes.
* **Space Complexity:** O(V^2) to store the 2D distance matrix. 

### Real-World Use Cases
1. **Network Routing:** OSPF (Open Shortest Path First) protocols use variations of this logic to build routing tables so data packets take the fastest route through the internet.
2. **Transportation & Logistics:** Finding the cheapest or fastest transit routes between every combination of cities in a logistics network.