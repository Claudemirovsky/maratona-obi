#include <stdio.h>
#include <stdlib.h>

int main() {
    int circleCount, shotCount, score = 0;
    scanf("%d %d", &circleCount, &shotCount);
    int radius[circleCount];
    for (int i = circleCount; i--;
         scanf("%d", &radius[i]), radius[i] *= radius[i])
        ;

    while (shotCount--) {
        int x, y;
        scanf("%d %d", &x, &y);

        int dist = abs(x * x) + abs(y * y);

        for (int i = 0; i < circleCount; i++)
            if (dist <= radius[i])
                score++;
            else
                break;
    }

    printf("%d\n", score);
    return 0;
}
