#include <stdio.h>

int main() {
    char c, show = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (c == ' ')
            show = 1;
        if (show) {
            putchar(c);
            show = 0;
        } else if (c == 'p')
            show = 1;
    }
    putchar('\n');
    return 0;
}
