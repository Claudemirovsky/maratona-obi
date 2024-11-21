#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int p = *(int *)a, n = *(int *)b;

    return (p > n) - (p < n);
}

int main() {
    int kids, milk, ans = 0;
    scanf("%d %d", &kids, &milk);
    int otim[kids];
    for (int i = 0; i < kids; ++i) {
        scanf("%d", &otim[i]);
        otim[i] = 100 - otim[i];
    }

    qsort(otim, kids, sizeof(int), compare);

    for (int i = 0; i < kids && milk >= otim[i]; ++i) {
        ++ans;
        milk -= otim[i];
    }

    printf("%d\n", ans);
    return 0;
}
