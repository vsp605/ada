#include <stdio.h>
#define MAX_ITEMS 100
// using memoization
int dp[MAX_ITEMS + 1][MAX_ITEMS + 1];
void initialize_dp(int n, int W) {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = -1;
        }
    }
}
int knapsack(int weight[], int value[], int n, int W) {
    if (n == 0 || W == 0) {
        return 0; 
    }

    if (dp[n][W] != -1) {
        return dp[n][W]; 
    }

    if (weight[n - 1] <= W) {
        int include_item = value[n - 1] + knapsack(weight, value, n - 1, W - weight[n - 1]);
        int exclude_item = knapsack(weight, value, n - 1, W);
        dp[n][W] = (include_item > exclude_item) ? include_item : exclude_item;
    } else {
        dp[n][W] = knapsack(weight, value, n - 1, W);
    }
    return dp[n][W];
}
int main() {
    int value[] = {60, 100, 120}; 
    int weight[] = {10, 20, 30};  
    int W = 50;  
    int n = sizeof(value) / sizeof(value[0]); 
    initialize_dp(n, W);
    int max_value = knapsack(weight, value, n, W);
    printf("Maximum value in Knapsack = %d\n", max_value);
    return 0;
}
