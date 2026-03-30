#include <stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            q[++r] = i;
        }
    }
    if (f <= r) {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}

int main() {
    int v;
    n = 4;
    int graph[20][20] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    for (i = 1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
        for (j = 1; j <= n; j++) {
            a[i][j] = graph[i][j];
        }
    }

    v = 1;
    visited[v] = 1;
    bfs(v);

    printf("Reachable nodes from %d:\n", v);
    for (i = 1; i <= n; i++) {
        if (visited[i]) {
            printf("%d\t", i);
        }
    }
    printf("\n");

    return 0;
}

