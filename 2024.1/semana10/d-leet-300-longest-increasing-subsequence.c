inline int max(int a, int b) { return a > b ? a : b; }
int lengthOfLIS(int *nums, int numsSize) {
    short dp[2501] = {0};
    int res = 0;

    for (int i = 0; i < numsSize; ++i)
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                res = max(dp[i], res);
            }
        }

    return res + 1;
}
