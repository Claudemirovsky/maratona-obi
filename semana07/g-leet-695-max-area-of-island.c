const int mx[] = {1, -1, 0, 0};
const int my[] = {0, 0, 1, -1};
int transverse(int **grid, int x, int y, int cols, int lines) {
    if (grid[y][x] == 0)
        return 0;
    grid[y][x] = 0;

    int size = 1;

    for (int i = 0; i < 4; i++) {
        int cx = x + mx[i], cy = y + my[i];
        if (cx >= 0 && cx < cols && cy >= 0 && cy < lines)
            size += transverse(grid, cx, cy, cols, lines);
    }
    return size;
}

int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize) {
    int lines = gridSize, max = 0;
    if (!lines)
        return 0;
    int cols = *gridColSize;

    for (int line = 0; line < lines; line++) {
        for (int col = 0; col < cols; col++) {
            if (grid[line][col]) {
                int size = transverse(grid, col, line, cols, lines);
                if (size > max)
                    max = size;
            }
        }
    }

    return max;
}
