/* Neps Academy - Sinuca */
#include <bits/stdc++.h>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

short sinuca(vector<short> &original, short size) {
    short newsize = size - 1, index = 0;
    vector<short> newvec(newsize);

    for (index = 0; index < newsize; index++) {

        if (original[index] == original[index + 1])
            newvec[index] = 1;
        else
            newvec[index] = -1;
    }

    if (newsize == 1)
        return newvec[0];
    return sinuca(newvec, newsize);
}
int main() {
    FASTIO;

    short size;
    cin >> size;
    vector<short> balls(size);

    for (int index = 0; index < size; cin >> balls[index++])
        ;

    if (sinuca(balls, size) == 1) {
        cout << "preta\n";
    } else
        cout << "branca\n";
    return 0;
}
