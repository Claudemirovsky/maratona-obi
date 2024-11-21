#include <stdio.h>

#define int unsigned long long

const int my[] = {1, -1, 0, 0};
const int mx[] = {0, 0, -1, 1};

int biggestNeighbour(int lines, int cols, int grid[lines][cols], int y, int x) {
    int max = 0;
    for (int i = 0; i < 4; ++i) {
        int ny = my[i] + y, nx = mx[i] + x;
        if (ny >= 0 && nx >= 0 && ny < lines && nx < cols && grid[ny][nx] > max)
            max = grid[ny][nx];
    }
    return max;
}

void f() {
    int lines, cols;
    scanf("%llu %llu", &lines, &cols);

    int grid[lines][cols];

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%llu", &grid[i][j]);
        }
    }

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < cols; ++j) {
            int *num = &grid[i][j];
            int largest = biggestNeighbour(lines, cols, grid, i, j);
            if (*num > largest)
                *num = largest;
            printf("%llu", *num);
            if (j + 1 < cols)
                putchar(' ');
            else
                putchar('\n');
        }
    }
}

signed main() {
    int tests;
    scanf("%llu", &tests);

    while (tests--)
        f();

    return 0;
}
