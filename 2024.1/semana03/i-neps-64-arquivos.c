#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
    int num = 0, filecount, limit;
    scanf("%d%d", &filecount, &limit);
    int files[filecount];

    for (int i = 0; i < filecount; scanf("%d", &files[i++]))
        ;

    qsort(files, filecount, sizeof(int), compare);

    for (int start = 0, end = filecount - 1; start <= end; end--) {
        num++;
        if ((files[start] + files[end]) <= limit)
            start++;
    }

    printf("%d\n", num);
    return 0;
}
