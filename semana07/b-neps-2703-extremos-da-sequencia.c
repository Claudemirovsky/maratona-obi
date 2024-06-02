#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int p = *(int *)a, n = *(int *)b;

    return (p > n) - (p < n);
}

#define LIMIT 4
int main() {
    int nums[LIMIT] = {0};
    for (int i = 0; i < LIMIT; scanf("%d", &nums[i++]))
        ;
    qsort(nums, LIMIT, sizeof(int), compare);

    printf("%d\n", nums[0] + nums[LIMIT - 1]);
    return 0;
}
