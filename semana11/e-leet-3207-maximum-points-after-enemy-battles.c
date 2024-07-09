#include <stdlib.h>

int compare(const void *a, const void *b) {
    int p = *(int *)a, n = *(int *)b;

    return (p < n) - (p > n);
}

long long maximumPoints(int *enemyEnergies, int enemyEnergiesSize,
                        int currentEnergy) {
    if (!currentEnergy)
        return 0ll;
    long long points = 0;
    qsort(enemyEnergies, enemyEnergiesSize, sizeof(int), compare);
    int minCost = enemyEnergies[enemyEnergiesSize - 1];
    int last = -1;
    while (last != (enemyEnergiesSize - 1)) {
        if (currentEnergy >= minCost) {
            points += currentEnergy / minCost;
            currentEnergy %= minCost;
        }

        if (points)
            currentEnergy += enemyEnergies[++last];
        else
            break;
    }
    return points;
}
