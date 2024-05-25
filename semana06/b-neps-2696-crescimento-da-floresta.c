#include <stdio.h>

int main() {
    long long initial, growth, target, days = 0;
    scanf("%lld %lld %lld", &initial, &growth, &target);

    while (initial < target) {
        days++;
        initial += initial * growth;
    }

    printf("%lld\n", days);
    return 0;
}
