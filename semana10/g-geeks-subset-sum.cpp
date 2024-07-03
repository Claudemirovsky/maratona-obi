#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

class Solution {
  public:
    bool isSubsetSum(vector<int> &arr, int sum) {
        char visited[10001] = {0};
        vector<int> nums;
        nums.push_back(0);
        for (int &num : arr) {
            for (int i = nums.size(); i--;) {
                int calc = nums[i] + num;
                if (calc == sum)
                    return true;
                if (visited[calc])
                    continue;

                visited[calc] = 1;
                nums.push_back(calc);
            }
        }

        return visited[sum];
    }
};

int32_t main() {
    FASTIO;
    Solution *s = new Solution();
    vector<int> x = {3, 34, 4, 12, 5, 2};
    bool res = s->isSubsetSum(x, 9);
    cout << res << endl;
    delete s;
    return 0;
}
