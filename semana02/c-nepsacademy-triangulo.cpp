/* Neps Academy -  Triângulo */
#include <algorithm>
#include <iostream>
#define FASTIO                                                                 \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0);                                                                \
    cout.tie(0)

#define previous(i) (nums[i] < (nums[i - 1] + nums[i - 2]))

using namespace std;

int main() {
    FASTIO;

    unsigned short nums[4];
    for (int i = 0; i < 4; cin >> nums[i++])
        ;

    sort(nums, nums + 4);

    if (previous(2) || previous(3))
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
