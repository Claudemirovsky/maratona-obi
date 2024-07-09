int numberOfAlternatingGroups(int *colors, int colorsSize) {
    int count = 0;
    for (int i = 0; i < colorsSize; ++i) {
        if (colors[i] == colors[(i + 2) % colorsSize] &&
            colors[i] != colors[(i + 1) % colorsSize])
            ++count;
    }
    return count;
}
