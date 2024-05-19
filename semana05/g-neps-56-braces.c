#include <stdio.h>

int main() {
    int lines, count = 0;
    scanf("%d", &lines);
    char ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '{') {
            count++;
        } else if (ch == '}') {
            if (count <= 0) {
                printf("N\n");
                return 0;
            }
            count--;
        }
    }

    printf("%c\n", count ? 'N' : 'S');
    return 0;
}
