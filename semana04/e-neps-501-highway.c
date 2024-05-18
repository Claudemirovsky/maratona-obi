#include <stdio.h>
#include <string.h>

#define zerofill(arr) memset(arr, 0, (cities + 1) * sizeof(arr[0]))

int main() {
    // Borrowed tips from J.Breno
    int cities;
    scanf("%d", &cities);
    char freq[cities + 1];
    int roads[cities + 1];
    zerofill(freq);
    zerofill(roads);
    for (int i = 0; i < cities; i++) {
        int next, current;
        scanf("%d %d", &next, &current);
        if (freq[current] >= 2 || freq[next] >= 2) {
            printf("N\n");
            return 0;
        }
        freq[next]++;
        freq[current]++;
        roads[next] = current;
    }

    for (int i = 1; i <= cities; i++) {
        if (freq[i] == 2)
            continue;
        printf("N\n");
        return 0;
    }

    int index = 1;
    while (roads[index]) {
        int t = roads[index];
        roads[index] = 0;
        cities--;
        index = t;
    }

    printf("%c\n", cities ? 'N' : 'S');
    return 0;
}
