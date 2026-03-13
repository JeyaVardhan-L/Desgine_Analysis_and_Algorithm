#include <stdio.h>
#include <stdlib.h>

#define INF 99999

// Helper function to print the solution matrix cleanly
void printSolution(int **dist, int v) {
    printf("\nShortest Distance Matrix between all pairs of vertices:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

// Core algorithm: finding shortest paths between all pairs using Dynamic Programming
void floydWarshall(int **graph, int v) {
    // Dynamically allocate our 2D distance matrix
    int **dist = (int **)malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++) {
        dist[i] = (int *)malloc(v * sizeof(int));
    }

    // Initialize distance matrix with the original graph weights
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // The magic 3 nested loops of Floyd-Warshall
    // k is the intermediate vertex we are trying to route through
    for (int k = 0; k < v; k++) {
        // i is the source vertex
        for (int i = 0; i < v; i++) {
            // j is the destination vertex
            for (int j = 0; j < v; j++) {
                // If routing through vertex 'k' is strictly shorter than the current path from 'i' to 'j', update it.
                // We also check against INF to prevent integer overflow weirdness.
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Show the results
    printSolution(dist, v);

    // Free the dynamically allocated distance matrix to prevent memory leaks
    for (int i = 0; i < v; i++) {
        free(dist[i]);
    }
    free(dist);
}

int main() {
    int v;

    printf("How many vertices does your graph have? ");
    if (scanf("%d", &v) != 1 || v <= 0) {
        printf("Please enter a valid positive number of vertices.\n");
        return 1;
    }

    // Dynamically allocating a 2D array (array of pointers) for the graph
    int **graph = (int **)malloc(v * sizeof(int *));
    if (graph == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < v; i++) {
        graph[i] = (int *)malloc(v * sizeof(int));
    }

    printf("\nEnter the adjacency matrix for the graph.\n");
    printf("Use %d to represent Infinity (no direct edge).\n", INF);
    printf("Example row for 4 vertices: 0 5 %d 10\n", INF);
    
    for (int i = 0; i < v; i++) {
        printf("Enter row %d (space-separated weights): ", i + 1);
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run the algorithm
    floydWarshall(graph, v);

    // Clean up the main graph memory row by row
    for (int i = 0; i < v; i++) {
        free(graph[i]);
    }
    free(graph); // Finally, free the array of pointers

    return 0;
}