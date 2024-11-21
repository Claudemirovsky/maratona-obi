#include <stdio.h>

int main() {
    int airports, flights;
    char matrix[1000][1000] = {{0}};
    scanf("%d %d", &airports, &flights);

    while (flights--) {
        int from, to;
        scanf("%d %d", &from, &to);
        matrix[--from][--to] = 1;
    }

    for (int i = 0; i < airports; i++) {
        int j = 0;
        for (; j < airports; j++) {
            if (j == i)
                continue;
            if (!matrix[i][j])
                break;
        }
        if (j == airports) {
            printf("S\n");
            return 0;
        }
    }

    printf("N\n");
    return 0;
}
