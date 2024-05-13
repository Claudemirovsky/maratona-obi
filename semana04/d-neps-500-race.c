#include <stdio.h>

int main() {
    int c1, dist1, v1;
    scanf("%d %d %d", &c1, &dist1, &v1);
    int c2, dist2, v2;
    scanf("%d %d %d", &c2, &dist2, &v2);

    printf("%d\n", ((double)dist1 / v1) < ((double)dist2 / v2) ? c1 : c2);
    return 0;
}
