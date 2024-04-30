#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isValid(int num, const int *setB, int size) {
    int i = 0, j = size - 1;

    while (i <= j) {
        if (setB[i] + setB[j] == num)
            return true;
        else if (setB[i] + setB[j] < num)
            i++;
        else
            j--;
    }
    return false;
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

bool binarySearch(const int *arr, const int size, const int target) {
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = start + ((end - start) / 2);
        if (arr[mid] == target)
            return true;

        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

int main() {
    int sizeA, sizeB, num;
    scanf("%d%d", &sizeA, &sizeB);
    int setA[sizeA], setB[sizeB], ihatetheantichrist[sizeB], added = 0;

    for (int i = 0; i < sizeA; scanf("%d", &setA[i++]))
        ;

    qsort(setA, sizeA, sizeof(int), compare); // Binary search agradece
    int len = 0;
    for (int i = 0; i < sizeB; i++) {
        scanf("%d", &num);
        setB[i] = num;
        if (!binarySearch(setA, sizeA, num)) {
            ihatetheantichrist[added++] = num;
            len = i + 1;
        }
    }

    if (added > 0) {
        qsort(setB, len, sizeof(int), compare);

        for (int i = 0; i < added; i++) {
            num = ihatetheantichrist[i];
            if (!isValid(num, setB, len)) {
                printf("%d\n", num);
                return 0;
            }
        }
    }

    printf("sim\n");

    return 0;
}
