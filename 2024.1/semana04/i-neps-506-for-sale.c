#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int p = *(int *)a, n = *(int *)b;

    return (p > n) - (p < n);
}

int main() {
    int owns, sell;
    scanf("%d %d", &owns, &sell);
    int buildings[owns], dist = owns - sell - 1;
    for (int i = 0; i < owns; scanf("%d", &buildings[i++]))
        ;

    qsort(buildings, owns, sizeof(int), compare);

    int min = 1 << 30, curr = 0;
    for (int i = 0; (i + dist) < owns; i++) {
        curr = buildings[i + dist] - buildings[i];

        if (curr < min)
            min = curr;
        if (min == 1)
            break;
    }

    printf("%d\n", min);
    return 0;
}
