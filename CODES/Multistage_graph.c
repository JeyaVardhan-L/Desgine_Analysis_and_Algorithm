#include <stdio.h>

#define INF 99999
#define N 8 // Total number of vertices in the graph

// Function to find the shortest path in a multistage graph
void shortestPath(int graph[N][N]) {
    // cost[i] will store the minimum cost to reach the destination from node i
    int cost[N]; 
    
    // next_node[i] will store the next node to travel to from node i
    int next_node[N]; 

    // Initialize the cost of the destination node (last node) to 0
    cost[N - 1] = 0;
    next_node[N - 1] = N - 1;

    // Work backwards from the second-to-last node down to the source (node 0)
    for (int i = N - 2; i >= 0; i--) {
        cost[i] = INF;

        // Check all possible next nodes 'j' that we can reach from current node 'i'
        for (int j = i + 1; j < N; j++) {
            
            // If there is a direct edge from i to j
            if (graph[i][j] != INF) {
                
                // Calculate the cost of going through node j
                // If it's cheaper than our current known cost for i, update it
                if (graph[i][j] + cost[j] < cost[i]) {
                    cost[i] = graph[i][j] + cost[j];
                    next_node[i] = j;
                }
            }
        }
    }

    // Print the results
    printf("Shortest Path Cost: %d\n", cost[0]);
    
    printf("Path: 0");
    int current = 0;
    while (current != N - 1) {
        current = next_node[current];
        printf(" -> %d", current);
    }
    printf("\n");
}

int main() {
    /* Graph represented as an adjacency matrix.
       INF means there is no direct edge between those two nodes.
       
       Stages:
       Stage 1: Node 0
       Stage 2: Nodes 1, 2, 3
       Stage 3: Nodes 4, 5, 6
       Stage 4: Node 7 (Destination)
    */
    int graph[N][N] = {
      // 0    1    2    3    4    5    6    7
        {INF, 1,   2,   5,   INF, INF, INF, INF}, // Node 0
        {INF, INF, INF, INF, 4,   11,  INF, INF}, // Node 1
        {INF, INF, INF, INF, 9,   5,   16,  INF}, // Node 2
        {INF, INF, INF, INF, INF, INF, 2,   INF}, // Node 3
        {INF, INF, INF, INF, INF, INF, INF, 18},  // Node 4
        {INF, INF, INF, INF, INF, INF, INF, 13},  // Node 5
        {INF, INF, INF, INF, INF, INF, INF, 2},   // Node 6
        {INF, INF, INF, INF, INF, INF, INF, INF}  // Node 7
    };

    printf("Calculating shortest path for the Multistage Graph...\n\n");
    shortestPath(graph);

    return 0;
}