#include <stdio.h>

int main() {
    int h, p, f, d;
    scanf("%d %d %d %d", &h, &p, &f, &d);
    // Eu ia fazer com uns ternários cabulosos,
    // mas ai ficou complexo demais, força-bruta ftw
    for (; f != p && f != h;) {
        f += d;
        if (f < 0)
            f = 15;
        else if (f > 15)
            f = 0;
    }

    printf("%c\n", f == p ? 'N' : 'S');
    return 0;
}
