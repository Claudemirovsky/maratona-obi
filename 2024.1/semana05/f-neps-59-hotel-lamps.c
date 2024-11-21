#include <stdio.h>

int main() {
    int i1, i2, f1, f2, moves = 0;
    scanf("%d %d %d %d", &i1, &i2, &f1, &f2);

    if (i1 != f1 || i2 != f2) {
        if (i2 != f2) {
            i1 = !i1;
            moves++;
        }
        if (i1 != f1)
            moves++;
    }

    printf("%d\n", moves);

    return 0;
}
