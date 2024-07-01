#define dps 4

int tribonacci(int n) {
    int dp[dps] = {0, 1, 1, -1};
    for (int i = 3; i <= n; ++i)
        dp[i % dps] = dp[(i - 1) % dps] + dp[(i - 2) % dps] + dp[(i - 3) % dps];
    return dp[n % dps];
}
