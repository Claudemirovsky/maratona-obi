int findCenter(int **edges, int edgesSize, int *edgesColSize) {
    int first = edges[0][0], second = edges[0][1];
    if (first == edges[1][0] || first == edges[1][1])
        return first;
    else
        return second;
}
