#include <string.h>

int max(int a, int b) { return a > b ? a : b; }
int longestCommonSubsequence(char *text1, char *text2) {
    int len1 = strlen(text1), len2 = strlen(text2);
    int p[1002] = {0}, dp[1002] = {0};

    for (int i = len1; i >= 0; --i) {
        char t1 = text1[i];
        if (!t1)
            continue;
        for (int j = len2; j >= 0; --j) {
            if (t1 == text2[j])
                dp[j] = p[j + 1] + 1;
            else
                dp[j] = max(p[j], dp[j + 1]);
        }
        memcpy(p, dp, sizeof(int) * len2);
    }

    return dp[0];
}
