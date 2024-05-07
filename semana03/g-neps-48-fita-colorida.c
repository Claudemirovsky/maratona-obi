#include <stdio.h>

int main() {
    int prev = -1, diff = 0, items, current, idx = 0;

    scanf("%d", &items);

    int nums[items];

    for (int i = 0; i < items; i++) {
        scanf("%d", &current);
        diff++;
        if (i == 0 && current == 0) {
            prev = diff = 0;
            nums[idx++] = 0;
        } else if (prev == -1 && current == 0) {
            while (diff-- > 1)
                nums[idx++] = diff;
            nums[idx++] = 0;
            prev = diff = 0;
        } else if ((i + 1) >= items && current == -1) {
            for (int x = 1; x <= diff; nums[idx++] = x++)
                ;
            diff = 0;
        } else if (current == 0) {
            int x = 1;
            diff--;
            if (diff > 0) {
                if (diff == 2) {
                    nums[idx++] = 1;
                    nums[idx++] = 1;
                } else {
                    for (; x < (diff + 1) / 2; nums[idx++] = x++)
                        ;
                    if ((diff & 1) == 0 && (x & 1) == 0)
                        nums[idx++] = x;
                    for (; x > 0; nums[idx++] = x--)
                        ;
                }
            }
            diff = nums[idx++] = 0;
        }
    }

    for (int i = 0; i < idx; i++) {
        printf("%d", nums[i]);
        if ((i + 1) < idx)
            putchar(' ');
    }
    printf("\n");

    return 0;
}
