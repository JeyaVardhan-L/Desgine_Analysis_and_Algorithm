#include <stdio.h>

// Number of vertices in the graph
#define V 4

/* Define Infinite as a large enough value. 
   This value will be used for vertices not connected to each other */
#define INF 99999

void printSolution(int dist[][V]);

// Solves the All-Pairs Shortest Path problem using Floyd Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    /* Initialize the solution matrix same as input graph matrix.
       dist[i][j] will be the shortest distance from i to j. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices.
       ---> Before iteration k, we have shortest distances between all pairs
            of vertices such that the shortest distances consider only 
            vertices from {0, 1, ..., k-1} as intermediate vertices.
       ---> After iteration k, vertex k is added to the set of intermediate
            vertices and the set becomes {0, 1, ..., k} */
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                
                // We add a check to ensure we don't add to INF (avoid overflow)
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances"
           " between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
            
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3,  INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    // Print input graph for clarity
    printf("Calculated Shortest Paths:\n");
    floydWarshall(graph);

    return 0;
}