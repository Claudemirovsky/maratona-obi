#include <stdio.h>

#define size 1000000

int main() {
    char cues[size] = {0};
    int queries, count = 0;
    scanf("%d", &queries);

    while (queries--) {
        int n;
        scanf("%d", &n);
        if (cues[n]) {
            cues[n]--;
        } else {
            cues[n]++;
            count += 2;
        }
    }

    printf("%d\n", count);
    return 0;
}
