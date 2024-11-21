#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

#define int int64_t

int32_t main() {
    FASTIO;
    int lines;
    cin >> lines;
    int arr[3];

    while (lines--) {
        cin >> arr[0] >> arr[1] >> arr[2];
        int n = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            n = min(n, abs(arr[0] - arr[i]) + abs(arr[1] - arr[i]) +
                           abs(arr[2] - arr[i]));
        }

        cout << n << endl;
    }
    return 0;
}
