#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

#define int int64_t

int32_t main() {
    FASTIO;
    int t;
    int limit = 1e5;
    cin >> t;
    string b = "";
    for (int i = 0; i < t && b.size() < limit; ++i) {
        string s(1, 'a' + i);
        b += s + b;
    }

    cout << b.substr(0, limit) << endl;
    return 0;
}
