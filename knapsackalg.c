#include <stdio.h>
#define MAX_ITEMS 100
// using bottom-up dynamic programming
int knapsack(int weight[], int value[], int n, int W)
 {
    int dp[n + 1][W + 1]; 
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0) 
            {
                dp[i][w] = 0; 
            } else if (weight[i - 1] <= w)
             {
                dp[i][w] = (value[i - 1] + dp[i - 1][w - weight[i - 1]] > dp[i - 1][w]) 
                            ? value[i - 1] + dp[i - 1][w - weight[i - 1]] 
                            : dp[i - 1][w];
            } else
             {
                dp[i][w] = dp[i - 1][w]; 
            }
        }
    }
    return dp[n][W];  
}
int main()
 {
    int value[] = {12,10,20,15}; 
    int weight[] = {2,1,3,2};  
    int W = 5;  
    int n = sizeof(value) / sizeof(value[0]); 
    int max_value = knapsack(weight, value, n, W);
    printf("Maximum value in Knapsack = %d\n", max_value);
    return 0;
}

