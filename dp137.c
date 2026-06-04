#include <stdio.h>
#include <limits.h>

int coinChange(int coins[], int n, int amount) {
    int dp[amount + 1];

    dp[0] = 0;

    for(int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;

    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < n; j++) {
            if(coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if(dp[i] > dp[i - coins[j]] + 1)
                    dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int amount = 11;
    int n = sizeof(coins) / sizeof(coins[0]);

    printf("Minimum Coins = %d\n",
           coinChange(coins, n, amount));

    return 0;
}