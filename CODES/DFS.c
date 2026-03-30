#include <stdio.h>

int a[20][20], reach[20], n;

void dfs(int v) {
    int i;
    reach[v] = 1;
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !reach[i]) {
            printf("\n%d->%d", v, i);
            dfs(i);
        }
    }
}

int main() {
    int i, j, count = 0;
    n = 4;
    int graph[20][20] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    for (i = 1; i <= n; i++) {
        reach[i] = 0;
        for (j = 1; j <= n; j++) {
            a[i][j] = graph[i][j];
        }
    }

    dfs(1);
    printf("\n");

    for (i = 1; i <= n; i++) {
        if (reach[i])
            count++;
    }
    if (count == n)
        printf("Graph is connected\n");
    else
        printf("Graph is not connected\n");

    return 0;
}