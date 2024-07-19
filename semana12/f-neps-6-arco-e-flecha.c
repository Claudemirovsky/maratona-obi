#include <stdio.h>
#include <stdlib.h>

#define int long long
int32_t compare(const void *a, const void *b) {
    const int(*p)[2] = a, (*n)[2] = b;

    return (**p > **n) - (**p < **n);
}

#define MAXV 100001
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
int tree[4 * MAXV];

void update(int val, int pos, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = val;
        return;
    }

    int mid = tl + (tr - tl) / 2;

    if (pos <= mid)
        update(val, pos, 2 * v, tl, mid);
    else
        update(val, pos, 2 * v + 1, mid + 1, tr);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (tr == r && tl == l)
        return tree[v];

    int mid = tl + (tr - tl) / 2;

    int sum_l = query(2 * v, tl, mid, l, min(r, mid));
    int sum_r = query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r);
    return sum_l + sum_r;
}

int32_t main() {
    int shots;
    scanf("%lld", &shots);
    int res = 0;
    int distances[shots][2];

    for (int i = 0; i < shots; ++i) {
        int x, y;
        scanf("%lld %lld", &x, &y);
        distances[i][0] = (x * x) + (y * y);
        distances[i][1] = i;
    }

    qsort(distances, shots, sizeof(int[2]), compare);

    for (int i = 0; i < shots; ++i) {
        int idx = distances[i][1];
        res += query(1, 0, shots - 1, 0, idx - 1);
        update(1, idx, 1, 0, shots - 1);
    }

    printf("%lld\n", res);
    return 0;
}
