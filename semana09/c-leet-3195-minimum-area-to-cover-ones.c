int minimumArea(int **grid, int gridSize, int *gridColSize) {
    int minX = 1001, maxX = 0;
    int minY = 1001, maxY = 0;
    int cols = *gridColSize;
    for (int y = 0; y < gridSize; ++y)
        for (int x = 0; x < cols; ++x)
            if (grid[y][x]) {
                if (y < minY)
                    minY = y;
                if (y > maxY)
                    maxY = y;
                if (x < minX)
                    minX = x;
                if (x > maxX)
                    maxX = x;
            }
    return ((maxX - minX) + 1) * ((maxY - minY) + 1);
}
