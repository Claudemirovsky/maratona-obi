#include <stdio.h>

int totalsteps = 0, lines, cols;

void dfs(char matrix[][cols], int x, int y, int steps) {
    if (totalsteps || matrix[y][x] == 0)
        return;

    steps++;
    if (matrix[y][x] == 3) {
        totalsteps = steps;
        return;
    }

    matrix[y][x] = 0;

    if ((x + 1) < cols && !totalsteps)
        dfs(matrix, x + 1, y, steps);
    if ((x - 1) >= 0 && !totalsteps)
        dfs(matrix, x - 1, y, steps);
    if ((y + 1) < lines && !totalsteps)
        dfs(matrix, x, y + 1, steps);
    if ((y - 1) >= 0 && !totalsteps)
        dfs(matrix, x, y - 1, steps);
}

int main() {
    int startX, startY;
    scanf("%d %d", &lines, &cols);
    char matrix[lines][cols];
    for (int y = 0; y < lines; y++)
        for (int x = 0; x < cols; x++) {
            int n;
            scanf("%d", &n);
            if (n == 2) {
                startX = x;
                startY = y;
            }
            matrix[y][x] = n;
        }
    dfs(matrix, startX, startY, 0);
    printf("%d\n", totalsteps);
    return 0;
}
