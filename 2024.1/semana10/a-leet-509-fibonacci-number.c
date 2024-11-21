#define dps 3

int fib(int n) {
    if (n < 2)
        return n;
    int dp[dps] = {0, 1, -1};
    for (int i = 2; i <= n; ++i)
        dp[i % dps] = dp[(i - 1) % dps] + dp[(i - 2) % dps];
    return dp[n % dps];
}
