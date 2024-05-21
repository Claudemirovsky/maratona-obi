#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char p = *(char *)a, n = *(char *)b;

    return (p > n) - (p < n);
}

int unique(char *str, int len) {
    qsort(str, len, sizeof(char), compare);
    int end = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && str[i] == str[i - 1])
            continue;
        str[end++] = str[i];
    }
    str[end] = 0;
    return end - 1;
}

void f() {
    int len;
    scanf("%d", &len);
    char orig[len + 1], copy[len + 1];
    scanf("%s\n", orig);
    strcpy(copy, orig);
    int newlen = unique(copy, len);

    char indexes['z' - 'a'] = {0};

    for (int i = 0; i <= newlen; indexes[copy[i] - 'a'] = i, i++)
        ;
    for (int i = 0; i < len;
         orig[i] = copy[newlen - indexes[orig[i] - 'a']], i++)
        ;
    puts(orig);
}
int main() {
    int tests;
    scanf("%d", &tests);

    while (tests--) {
        f();
    }

    return 0;
}
