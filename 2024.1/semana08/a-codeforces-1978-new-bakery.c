#include <stdio.h>

#define int long long

signed main() {
    int lines;
    scanf("%lld", &lines);

    while (lines--) {
        int n_buns, a_price, b_first;
        scanf("%lld %lld %lld", &n_buns, &a_price, &b_first);
        int x = b_first - n_buns + 1;
        int res = 0;
        if (a_price >= b_first) {
            res = n_buns * a_price; // pnc da promoção
        } else if (x >= a_price) {
            res = n_buns * ((b_first + x) >> 1);
        } else {
            x = b_first - a_price;
            res = (a_price * (n_buns - x)) +
                  (x * ((b_first + b_first - x + 1) >> 1));
        }

        printf("%lld\n", res);
    }
    return 0;
}
