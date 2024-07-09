int numWaterBottles(int numBottles, int numExchange) {
    return (numBottles - 1) / (numExchange - 1) + numBottles;
}
