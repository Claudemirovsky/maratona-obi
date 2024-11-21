#include <stdio.h>

int main() {
    int days, initial, current;
    scanf("%d %d", &days, &initial);
    int min = initial;

    while (days--) {
        scanf("%d", &current);
        initial += current;
        if (initial < min)
            min = initial;
    }

    printf("%d\n", min);

    return 0;
}
