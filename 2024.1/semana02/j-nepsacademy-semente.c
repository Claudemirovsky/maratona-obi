#include <stdio.h>

#define upddiff(v)                                                             \
    diff = (v - prev) / 2;                                                     \
    if (diff > max_diff) {                                                     \
        max_diff = diff;                                                       \
    }

int main() {
    int size, seedcount, current = 0, prev = 0, max_diff = 0, diff;
    scanf("%d%d", &size, &seedcount);

    for (int s = 0; s < seedcount; s++) {
        scanf("%d", &current);
        if (prev) {
            upddiff(current);
        } else {
            max_diff = current - 1;
        }
        prev = current;
    }

    if ((size - current) > max_diff)
        max_diff = size - current;

    printf("%d\n", max_diff);

    return 0;
}
