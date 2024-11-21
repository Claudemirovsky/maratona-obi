#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *diStringMatch(char *s, int *returnSize) {
    int len = strlen(s), min = 0, max = len;
    *returnSize = len + 1;
    int *res = malloc((max + 1) * sizeof(int));
    if (res == NULL)
        return NULL;

    for (int i = 0; i < len; ++i) {
        if (s[i] == 'D')
            res[i] = max--;
        else
            res[i] = min++;
    }
    res[len] = min;
    return res;
}
