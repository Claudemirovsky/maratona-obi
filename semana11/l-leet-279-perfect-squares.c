#include <limits.h>

int min(int a, int b) { return a < b ? a : b; }
int numSquares(int n) {
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        dp[i] = INT_MAX;

    for (int i = 1; i <= 100; ++i) {
        int num = i * i;
        if (num == n)
            return 1;
        else if (num > n)
            break;

        for (int j = 1; j <= n; ++j) {
            if (num <= j) {
                int val = dp[j - num] + 1;
                dp[j] = min(dp[j], val);
            }
        }
    }

    return dp[n];
}
