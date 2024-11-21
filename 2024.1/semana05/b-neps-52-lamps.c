#include <stdio.h>

int main() {
    char state[3] = {0};
    int movements;
    scanf("%d", &movements);

    while (movements--) {
        int m;
        scanf("%d", &m);
        state[m] = !state[m];
        if (m == 2)
            state[1] = !state[1];
    }

    printf("%d\n%d\n", state[1], state[2]);

    return 0;
}
