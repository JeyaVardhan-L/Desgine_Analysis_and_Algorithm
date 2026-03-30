#include <stdio.h>

// Helper function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    // Create a 2D array for DP
    int dp[n + 1][W + 1];

    // Build table dp[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } 
            else if (wt[i - 1] <= w) {
                // Max of including the item or not including it
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else {
                // Cannot include the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The last cell contains the maximum value
    return dp[n][W];
}
//this block creates , the loop 
int main() {
    // Example Input
    int val[] = {60, 100, 120}; // Values of the items
    int wt[] = {10, 20, 30};    // Weights of the items
    int W = 50;                 // Capacity of the knapsack
    
    // Calculate the number of items
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Knapsack = %d\n", knapSack(W, wt, val, n));

    return 0;
}

