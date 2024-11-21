const int mx[] = {1, -1, 0, 0};
const int my[] = {0, 0, 1, -1};
void transverse(int **grid1, int **grid2, int x, int y, int cols, int lines,
                int *num) {
    if (!grid2[x][y])
        return;
    if (!grid1[x][y]) {
        *num = 0;
    }
    grid2[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int cx = x + mx[i], cy = y + my[i];
        if (cx >= 0 && cx < lines && cy >= 0 && cy < cols)
            transverse(grid1, grid2, cx, cy, cols, lines, num);
    }
}
int countSubIslands(int **grid1, int grid1Size, int *grid1ColSize, int **grid2,
                    int grid2Size, int *grid2ColSize) {
    int count = 0, lines = grid2Size, cols = *grid2ColSize;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid2[i][j]) {
                int increment = 1;
                transverse(grid1, grid2, i, j, cols, lines, &increment);
                count += increment;
            }
        }
    }
    return count;
}
