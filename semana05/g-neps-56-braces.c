#include <malloc.h>
#include <stdio.h>

int main() {
    int lines, count = 0;
    scanf("%d", &lines);
    lines++;
    while (lines--) {
        char *str = NULL;
        size_t len = 30;
        getline(&str, &len, stdin);
        for (int i = 0; i < len; i++) {
            char ch = str[i];
            if (ch == '{') {
                count++;
            } else if (ch == '}') {
                if (count <= 0) {
                    printf("N\n");
                    free(str);
                    return 0;
                }
                count--;
            }
        }
        free(str);
    }

    printf("%c\n", count ? 'N' : 'S');
    return 0;
}
