void transverse(char **grid, int x, int y, int cols, int lines) {
    if (grid[y][x] == '0')
        return;
    grid[y][x] = '0';

    if ((x + 1) < cols) // direita
        transverse(grid, x + 1, y, cols, lines);
    if ((x - 1) >= 0) // esquerda
        transverse(grid, x - 1, y, cols, lines);
    if ((y + 1) < lines) // cima
        transverse(grid, x, y + 1, cols, lines);
    if ((y - 1) >= 0) // baixo
        transverse(grid, x, y - 1, cols, lines);
}

int numIslands(char **grid, int gridSize, int *gridColSize) {
    int lines = gridSize, islands = 0;
    if (!lines)
        return 0;
    int cols = *gridColSize;

    for (int line = 0; line < lines; line++) {
        for (int col = 0; col < cols; col++) {
            if (grid[line][col] == '1') {
                islands++;
                transverse(grid, col, line, cols, lines);
            }
        }
    }

    return islands;
}
