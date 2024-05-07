#include <stdio.h>

int main() {
    unsigned arr[200000][2] = {0}, current, next, letters;
    char ch;
    scanf("%u", &letters);

    while (letters--) {
        scanf("%u %c %u", &current, &ch, &next);
        arr[current][0] = ch;
        arr[current][1] = next;
    }

    for (unsigned next = 0; next != 1; next = arr[next][1]) {
        putchar(arr[next][0]);
    }
    putchar('\n');

    return 0;
}
