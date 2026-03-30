#include <stdio.h>

int w[10];
int x[10];
int m;

void sumOfSubsets(int s, int k, int r) {
    int i;
    x[k] = 1;
    if (s + w[k] == m) {
        printf("Subset: ");
        for (i = 0; i <= k; i++) {
            if (x[i] == 1) {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
    } else if (s + w[k] + w[k + 1] <= m) {
        sumOfSubsets(s + w[k], k + 1, r - w[k]);
    }
    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k]);
    }
}

int main() {
    int n = 5, i, sum = 0;
    int arr[] = {1, 2, 5, 6, 8};
    m = 9;

    for(i = 0; i < n; i++) {
        w[i] = arr[i];
        sum += w[i];
    }

    if (sum < m || w[0] > m) {
        printf("No subset possible\n");
    } else {
        sumOfSubsets(0, 0, sum);
    }
    return 0;
}