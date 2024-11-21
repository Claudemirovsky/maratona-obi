#include <limits.h>

unsigned min(unsigned a, unsigned b) { return a < b ? a : b; }

int coinChange(int *coins, int coinsSize, int amount) {
    unsigned dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
        dp[i] = INT_MAX;
    for (int i = 0; i < coinsSize; ++i) {
        if (coins[i] == amount)
            return 1;

        if (coins[i] > amount)
            continue;
        for (int j = 1; j <= amount; ++j) {
            if (coins[i] <= j) {
                unsigned val = dp[j - coins[i]] + 1;
                dp[j] = min(val, dp[j]);
            }
        }
    }
    int res = (int)dp[amount];
    return res == INT_MAX ? -1 : res;
}
