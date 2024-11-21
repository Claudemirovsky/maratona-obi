/* Neps Academy - Gangorra */
#include <stdio.h>

int main() {
    unsigned short c1, p1, c2, p2;
    scanf("%hu%hu%hu%hu", &c1, &p1, &c2, &p2);
    c1 *= p1;
    c2 *= p2;

    if (c1 == c2)
        putchar('0');
    else if (c2 > c1)
        putchar('1');
    else
        printf("-1");
    putchar('\n');
    return 0;
}
