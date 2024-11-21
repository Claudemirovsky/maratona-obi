/* beecrowd - 2415 */
#include <stdio.h>

int main() {
    unsigned short items, last = 0, most = 1, repeats = 1, num;
    scanf("%hu", &items);

    while (items--) {
        scanf("%hu", &num);
        if (num == last) {
            repeats++;
        } else {
            if (repeats > most)
                most = repeats;
            repeats = 1;
            last = num;
        }
    }
    if (repeats > most)
        most = repeats;

    printf("%hu\n", most);

    return 0;
}
