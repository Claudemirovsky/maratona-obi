#define min(a, b) (a < b ? a : b)
int minCostClimbingStairs(int *cost, int costSize) {
    if (costSize == 2)
        return min(cost[0], cost[1]);
    // Tribonacci 2: eletric boogaloo
    for (int i = 2; i < costSize; ++i)
        cost[i] += min(cost[i - 2], cost[i - 1]);

    return min(cost[costSize - 2], cost[costSize - 1]);
}
