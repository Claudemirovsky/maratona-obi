#include <stdio.h>

int main() {
    unsigned short a, b, c, d;
    scanf("%hu%hu%hu%hu", &a, &b, &c, &d);

    printf("%c\n", (a == (b + c + d) && b == c && (b + c) == d) ? 'S' : 'N');
    return 0;
}
