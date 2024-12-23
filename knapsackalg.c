#include <stdio.h>

#define MAX_ITEMS 100

// Using bottom-up dynamic programming
void knapsack(int weight[], int value[], int n, int W, int dp[n + 1][W + 1]) {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                dp[i][w] = (value[i - 1] + dp[i - 1][w - weight[i - 1]] > dp[i - 1][w])
                                ? value[i - 1] + dp[i - 1][w - weight[i - 1]]
                                : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
}

int main() {
    int value[4] = {12, 10, 20, 15};
    int weight[4] = {2, 1, 3, 2};
    int W = 5;
    int n = sizeof(value) / sizeof(value[0]);

    // Create dp array to store the table for visualization
    int dp[n + 1][W + 1];

    // Call knapsack function to fill the dp table
    knapsack(weight, value, n, W, dp);

    // The maximum value in Knapsack will be at dp[n][W]
    printf("Maximum value in Knapsack = %d\n", dp[n][W]);

    // Print the dp table
    printf("\nDynamic Programming Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
