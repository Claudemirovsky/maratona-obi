#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        vector<int> dp(W + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = W; j >= 0; --j) {
                int prev = i - 1;
                if (wt[prev] <= j) {
                    int v = val[prev] + dp[j - wt[prev]];
                    dp[j] = max(dp[j], v);
                }
            }
        }

        return dp[W];
    }
};
