#include <stdio.h>

int main() {
    char a, b, c, d;
    scanf("%c %c %c %c", &a, &b, &c, &d);

    printf("%c\n", a == c || b == d ? 'V' : 'F');
    return 0;
}
