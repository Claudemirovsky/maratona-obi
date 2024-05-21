#include <stdio.h>

int main() {
    int lines;
    scanf("%d", &lines);

    while (lines--) {
        int a, b, screens = 0;
        scanf("%d %d", &a, &b);
        while (a || b) {
            screens++;
            int spaces = 15;
            for (int i = 2; i && b; i--, b--, spaces -= 4)
                ;

            a = spaces > a ? 0 : a - spaces;
        }
        printf("%d\n", screens);
    }
    return 0;
}
