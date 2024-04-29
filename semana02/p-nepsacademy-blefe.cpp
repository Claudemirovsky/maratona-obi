#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

bool isValid(int num, const int *setB, int size) {
    int i = 0, j = size - 1;

    while (i <= j) {
        if (setB[i] + setB[j] == num)
            return true;
        else if (setB[i] + setB[j] < num)
            i++;
        else
            j--;
    }
    return false;
}

int main() {
    FASTIO;
    int sizeA, sizeB, num;
    cin >> sizeA >> sizeB;
    int setA[sizeA], setB[sizeB];
    vector<int> ihatetheantichrist;

    for (int i = 0; i < sizeA; cin >> setA[i++])
        ;

    sort(setA, setA + sizeA); // Binary search agradece
    int len = 0;
    for (int i = 0; i < sizeB; i++) {
        cin >> num;
        setB[i] = num;
        if (!binary_search(setA, setA + sizeA, num)) {
            ihatetheantichrist.push_back(num);
            len = i + 1;
        }
    }

    if (!ihatetheantichrist.empty()) {
        sort(setB, setB + len);

        for (int num : ihatetheantichrist) {
            if (!isValid(num, setB, len)) {
                cout << num << '\n';
                return 0;
            }
        }
    }

    cout << "sim\n";

    return 0;
}
