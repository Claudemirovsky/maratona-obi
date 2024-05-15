#include <malloc.h>
#include <stdio.h>

int main() {
    int cities;
    scanf("%d", &cities);
    int *roads = calloc(cities + 1, sizeof(int));
    char *visited = calloc(cities + 1, sizeof(char));

    for (int i = 0; i < cities; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        roads[c1] = c2;
    }

    int current = 1, total = 0;
    for (int i = 0; i < cities; i++) {
        if (!roads[current])
            break;
        if (!visited[current]) {
            visited[current] = 1;
            total++;
        }
        current = roads[current];
    }
    free(roads);
    free(visited);

    printf("%c\n", (total == cities) ? 'S' : 'N');
    return 0;
}
