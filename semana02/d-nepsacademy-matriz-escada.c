#include <stdio.h>

int main() {
    short height, width, most_left = -1, i;
    scanf("%hd%hd", &height, &width);
    unsigned num;

    while (height--) {
        char skip = 0;
        short current_lefty = -1;
        for (i = 0; i < width; i++) {
            scanf("%u", &num);
            if (skip)
                continue;

            if (!num)
                current_lefty++;
            else if (most_left == -1 && current_lefty == -1) {
                most_left = 0;
                skip = 1;
            } else if (current_lefty <= most_left) {
                printf("N\n");
                return 0;
            } else {
                skip = 1;
                most_left = current_lefty;
            }
        }
    }
    printf("S\n");
    return 0;
}
