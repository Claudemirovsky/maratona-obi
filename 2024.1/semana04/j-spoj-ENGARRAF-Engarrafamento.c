#include <limits.h>
#include <stdio.h>

int minCostIndex(int *cost, char *visited, int size) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < size; i++)
        // if it wasnt visited yet AND its the closest item, go to it
        // Note that if there's no unvisited neighbour
        // or not even a single neighbour (INT_MAX distance), we'll return -1.
        if (!visited[i] && cost[i] <= min)
            min = cost[i], min_index = i;

    return min_index;
}

int digimonrussomaldito(int size, int matrix[][size], int start, int target) {
    int cost[size];
    char visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
        cost[i] = INT_MAX;
    }

    cost[start] = 0;

    for (int i = 0; i < size; i++) {
        // >imagine using a set or priority_queue
        // me and my homies just force a N-vertices iteration
        int closest = minCostIndex(cost, visited, size);

        if (closest == target)
            return cost[target];
        if (closest == -1 || cost[closest] == INT_MAX)
            continue;

        visited[closest] = 1;

        int curr_cost = cost[closest];
        for (int j = 0; j < size; j++) {
            int pathcost = matrix[closest][j];
            if (visited[j] || pathcost == INT_MAX)
                continue;

            pathcost += curr_cost;
            if (pathcost < cost[j])
                cost[j] = pathcost;
        }
    }

    return cost[target];
}

int main() {
    int places, roads;
    //                                               I HATE SPOJ.
    while (scanf("%d %d", &places, &roads) && (places || roads)) {
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
