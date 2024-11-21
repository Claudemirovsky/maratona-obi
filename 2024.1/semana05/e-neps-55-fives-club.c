#include <stdio.h>

int main() {
    int total, t;
    scanf("%d", &total);

    for (int i = 3; i--; scanf("%d", &t), total -= t)
        ;
    for (int i = 3; i--; scanf("%d", &t), total += t)
        ;

    scanf("%d", &t);
    total -= t;
    printf("%c\n", total == 0 ? 'N' : 'S');
    return 0;
}
