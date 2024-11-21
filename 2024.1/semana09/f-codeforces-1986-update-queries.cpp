#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

void solve() {
    int len, updates;
    cin >> len >> updates;
    string str;
    str.reserve(len);
    cin >> str;
    char used[100010] = {0};
    vector<int> nums;
    for (int i = 0; i < updates; ++i) {
        int x;
        cin >> x;
        if (!used[x]) {
            used[x] = 1;
            nums.push_back(x);
        }
    }

    string newstr;
    newstr.reserve(updates);
    cin >> newstr;
    sort(newstr.begin(), newstr.end());
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
        str[nums[i] - 1] = newstr[i];
    cout << str << endl;
}
int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
