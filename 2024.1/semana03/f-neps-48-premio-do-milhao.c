#include <stdio.h>

int main() {
    int total, passed = 0, amount = 0, current;

    scanf("%d", &total);

    while (total--) {
        passed++;
        scanf("%d", &current);
        amount += current;
        if (amount >= 1000000) {
            printf("%d\n", passed);
            break;
        }
    }
    return 0;
}
