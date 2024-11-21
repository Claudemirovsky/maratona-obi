#include <stdio.h>

int lines, cols;

#define isValid(x, y, matrix)                                                  \
    (x >= 0 && x < cols && y < lines && y >= 0 && matrix[y][x])

int main() {
    scanf("%d %d", &lines, &cols);
    int matrix[lines][cols], currL, currC;
    scanf("%d %d", &currL, &currC);
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < cols; scanf("%d", &matrix[i][j++]))
            ;

    currC--;
    currL--;

    while (1) {
        matrix[currL][currC] = 0;
        if (isValid(currC + 1, currL, matrix))
            currC++;
        else if (isValid(currC - 1, currL, matrix))
            currC--;
        else if (isValid(currC, currL + 1, matrix))
            currL++;
        else if (isValid(currC, currL - 1, matrix))
            currL--;
        else
            break;
    }

    printf("%d %d\n", currL + 1, currC + 1);
    return 0;
}
