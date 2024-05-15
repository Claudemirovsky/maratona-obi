#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
    int zones[4];
    for (int i = 4; i--; scanf("%d", &zones[i]))
        ;

    qsort(zones, 4, sizeof(int), compare);

    printf("%c\n",
           ((zones[0] * zones[3]) == (zones[1] * zones[2])) ? 'S' : 'N');
    return 0;
}
