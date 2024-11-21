#include <limits.h>
#include <stdio.h>

int chtonum(char ch) { return ch - '0'; }

void solve() {
    int len;
    scanf("%d", &len);
    if (len <= 2) {
        int x;
        scanf("%d", &x);
        printf("%d\n", x);
        return;
    }

    char str[21] = {0};
    scanf(" %s", str);

    int min = INT_MAX;
    for (int i = 0; i < len - 1; ++i) {
        unsigned short arr[21] = {0}, idx = 0;
        int sum = 0, hasOne = 0;
        for (unsigned short j = 0; j < len; ++j) {
            if (i == j) {
                ++j;
                arr[idx++] = (chtonum(str[i]) * 10) + chtonum(str[i + 1]);
            } else {
                arr[idx++] = chtonum(str[j]);
            }
        }

        for (int j = 0; j < idx; ++j) {
            if (!arr[j]) { // se tem um zero, dá pra anular tudo e só printar
                           // zero
                min = 0;
                break;
            }
            if (arr[j] == 1)
                // Se tem 1, N*1 = N, ent n fazemos nada kkkkkk, vlw hilbert
                hasOne = 1;
            else
                sum += arr[j]; // de resto spamma soma
        }

        if (!sum && hasOne)
            ++sum; // maldito corner case
        min = sum < min ? sum : min;
        if (!min)
            break;
    }
    printf("%d\n", min);
}

int main() {
    int tests;
    scanf("%d", &tests);

    while (tests--)
        solve();
    return 0;
}
