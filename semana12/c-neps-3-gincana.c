#include <stdio.h>

#define int long long
int gcd(int a, int b) {
    if (a && b)
        while ((a %= b) && (b %= a)) {
        }
    return a | b;
}

signed main() {
    int a, b;
    scanf("%lld %lld", &a, &b);

    int res = 0;
    while ((res = gcd(a, b)) != 1)
        --b;

    printf("%lld\n", b);
    return 0;
}
