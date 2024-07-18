#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

#define int int64_t

#define gauss(x) (x * (x + 1)) / 2

int32_t main() {
    FASTIO;
    int t;
    cin >> t;
    multiset<int, less<int>> distances;
    int biggest = -1;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int dist = llabs(x * x) + llabs(y * y);
        auto iter =
            upper_bound(distances.begin(), distances.end(), dist,
                        [](const int &a, const int &b) { return a >= b; });

        if (iter != distances.end() && dist >= biggest) {
            biggest = dist;
        }
        distances.insert(dist);
    }

    if (biggest == -1)
        cout << "0\n";
    else {
        int p = distance(distances.begin(), distances.upper_bound(biggest));
        --p;
        cout << gauss(p) << endl;
    }
    return 0;
}
