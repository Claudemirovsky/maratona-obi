#include <stdio.h>
#include <stdlib.h>

#define int long long

int findLower(int arr[], int len, int target) {
    int start = 0, end = len - 1;

    while (start < end) {
        int mid = start + ((end - start) / 2);

        if (arr[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }

    return end;
}

signed main() {
    int circleCount, shotCount, score = 0;
    scanf("%lld %lld", &circleCount, &shotCount);
    int radius[circleCount];
    for (int i = 0; i < circleCount;
         scanf("%lld", &radius[i]), radius[i] *= radius[i], i++)
        ;

    while (shotCount--) {
        int x, y;
        scanf("%lld %lld", &x, &y);

        int dist = llabs(x * x) + llabs(y * y);
        if (dist > radius[circleCount - 1])
            continue;

        score += circleCount - findLower(radius, circleCount, dist);
    }

    printf("%lld\n", score);
    return 0;
}
