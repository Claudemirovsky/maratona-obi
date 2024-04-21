#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

int main() {
    FASTIO;

    short dims[3] = {0};
    short height, width;

    cin >> dims[0] >> dims[1] >> dims[2] >> height >> width;
    sort(dims, dims + 3);

    if ((dims[0] <= height && dims[1] <= width) ||
        (dims[0] <= width && dims[1] <= height))
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
