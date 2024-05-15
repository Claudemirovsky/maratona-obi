#include <stdio.h>
#include <string.h>

int main() {
    int cities;
    scanf("%d", &cities);
    int roads[cities + 1];
    memset(roads, 0, sizeof(roads));
    char visited[cities + 1];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < cities; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        roads[c1] = c2;
    }

    int current = 1, total = 0;
    for (int i = 0; i < cities && roads[current] && !visited[current]; i++) {
        visited[current] = 1;
        total++;
        current = roads[current];
    }

    printf("%c\n", (total >= cities) ? 'S' : 'N');
    return 0;
}
