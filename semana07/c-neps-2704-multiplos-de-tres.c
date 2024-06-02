#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    char p = *(char *)a, n = *(char *)b;

    return (p < n) - (p > n);
}

#define LIMIT 10
int main() {
    char digits[LIMIT] = {0}, sum = 0, i = 0, ch;
    for (; scanf("%c", &ch) != EOF && ch != '\n' && i < LIMIT; i++) {
        digits[i] = ch;
        sum += digits[i] - '0';
    }

    if ((sum % 3) == 0) {
        qsort(digits, i, sizeof(char), compare);
        for (int x = 0; x < i; putchar(digits[x++]))
            ;
    } else
        printf("-1\n");
    return 0;
}
