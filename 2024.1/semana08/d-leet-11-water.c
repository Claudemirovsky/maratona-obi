#include <stdio.h>

#define min(x, y) ((x < y) ? x : y)

int maxArea(int *height, int heightSize) {
    int max = 0, i = 0, j = heightSize - 1;
    while (i < j) {
        int start = height[i], end = height[j];
        int size = (j - i) * min(start, end);
        if (size > max)
            max = size;
        if (start > end)
            --j;
        else
            ++i;
    }

    return max;
}
