/* Neps Academy - Flipper */
#include <stdio.h>

int main() {
    unsigned short R, P;
    scanf("%hu %hu", &P, &R);

    if (P == 0)
        putchar('C');
    else if (R == 0)
        putchar('B');
    else
        putchar('A');

    putchar('\n');
    return 0;
}
