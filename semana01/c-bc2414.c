/* beecrowd - 2414 */
#include <stdio.h>

int main() {
    unsigned short num = 0, maior = 0;
    do {
        if (num > maior)
            maior = num;
        scanf("%hu", &num);
    } while (num);
    printf("%hu\n", maior);
    return 0;
}
