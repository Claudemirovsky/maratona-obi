/* beecrowd - 2411 */
#include <stdio.h>

int main() {
    int moves[][2] = {{1, 2},  // 1
                      {2, 1},  // 2
                      {2, -1}, // 3
                      {1, -2}, // 4

                      {-1, -2}, // 5
                      {-2, -1}, // 6
                      {-2, 1},  // 7
                      {-1, 2}}; // 8
    unsigned movements, mov, x, y, success = 0, current[2] = {4, 3};
    scanf("%u", &movements);

    while (movements--) {
        scanf("%u", &mov);
        mov--;
        x = current[0] += moves[mov][0];
        y = current[1] += moves[mov][1];
        success++;
        if ((x == 1 && y == 3) || (x == 2 && (y == 3 || y == 5)) ||
            (x == 5 && y == 4)) {
            break;
        }
    }
    printf("%u\n", success);
    return 0;
}
