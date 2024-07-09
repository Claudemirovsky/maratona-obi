int passThePillow(int n, int time) {
    int mod = time % (n - 1);
    if ((time / (n - 1)) & 1) {
        return n - mod;
    } else
        return mod + 1;
}
