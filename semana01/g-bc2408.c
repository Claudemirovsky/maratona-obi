#include <stdio.h>

int main() {
    unsigned short a, b, c;
    scanf("%hu%hu%hu", &a, &b, &c);

    // KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
    printf("%hu\n", c > a && a > b   ? a
                    : b > a && a > c ? a
                    : a > b && b > c ? b
                    : c > b && b > a ? b
                    : a > c && c > b ? c
                    : b > c && c > a ? c
                                     : 0);
    return 0;
}
