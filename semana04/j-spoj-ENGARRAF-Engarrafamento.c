#include <limits.h>
#include <stdio.h>

int minDistIndex(int *dist, char *visited, int size) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < size; i++)
        // if it wasnt visited yet AND its the closest item, go to it
        // Note that if there's no unvisited neighbour
        // or not even a single neighbour (INT_MAX distance), we'll return -1.
        if (!visited[i] && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}

int digimonrussomaldito(int size, int matrix[][size], int start, int target) {
    int dist[size];
    char visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
        dist[i] = INT_MAX;
    }

    dist[start] = 0;

    for (int i = 0; i < size; i++) {
        int closest = minDistIndex(dist, visited, size);
        if (closest == target)
            return dist[target];
        if (closest == -1 || dist[closest] == INT_MAX)
            continue;
        visited[closest] = 1;
        int distc = dist[closest];
        for (int j = 0; j < size; j++) {
            if (!visited[j] && matrix[closest][j] != INT_MAX &&
                (distc + matrix[closest][j]) < dist[j]) {
                dist[j] = distc + matrix[closest][j];
            }
        }
    }

    return dist[target];
}

int main() {
    int places, roads;

    while (scanf("%d %d", &places, &roads) && places && roads) {
        int cost[places][places], start, target;

        for (int i = 0; i < places; i++)
            for (int j = 0; j < places; j++)
                cost[i][j] = INT_MAX;

        while (roads--) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            cost[a - 1][b - 1] = c;
        }

        scanf("%d %d", &start, &target);

        int dist = digimonrussomaldito(places, cost, start - 1, target - 1);
        printf("%d\n", dist == INT_MAX ? -1 : dist);
    }
    return 0;
}
