#include <stdio.h>

int main() {
    unsigned people = 0;

    while (scanf("%u", &people) && people) {
        unsigned total = 0, prev = 0, current = 0;
        while (people--) {
            scanf("%u", &current);
            if ((current - prev) >= 10 || !total) {
                total += 10;
            } else {
                total += current - prev;
            }
            prev = current;
        }

        printf("%d\n", total);
    }
    return 0;
}
