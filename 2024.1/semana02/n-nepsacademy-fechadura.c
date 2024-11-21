#include <stdio.h>

int main() {
    // nota: se usar unsigned, dá pau em alguns casos.
    short pincount, expected_size, diff, i;
    unsigned moves = 0;
    scanf("%hd%hd", &pincount, &expected_size);
    short pins[pincount];

    for (i = 0; i < pincount; scanf("%hd", &pins[i++]))
        ;

    for (i = 0; i < pincount - 1; i++) {
        // "O que passa de mim é podre" - Nikola Tesla
        if (pins[i] > expected_size) {
            diff = pins[i] - expected_size;
            moves += diff;
            pins[i + 1] -= diff;
        } else if (pins[i] < expected_size) {
            diff = expected_size - pins[i];
            moves += diff;
            pins[i + 1] += diff;
        }
    }

    printf("%u\n", moves);
    return 0;
}
