#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int16_t max = SHRT_MIN; // foi mal, glauber

void calc_max(int row, int column, int maxrows, int maxcols,
              int16_t matrix[][maxcols]) {
    int16_t num = matrix[row][column], calc = 0;
    for (int i = row; i < maxrows; i++) {
        for (int j = column; j < maxcols; j++) {
            if (matrix[i][j] <= num)
                continue;
            calc = matrix[i][j] - num;
            if (calc > max)
                max = calc;
        }
    }
}

int main() {
    int16_t rows, columns;
    scanf("%hd %hd", &rows, &columns);
    int16_t matrix[rows][columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; scanf("%hd", &matrix[i][j++]))
            ;

    int16_t min_col[columns];
    for (int i = 0; i < columns; min_col[i++] = SHRT_MAX)
        ;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int16_t num = matrix[i][j];
            if (num >= min_col[j])
                continue;
            min_col[j] = num;

            calc_max(i, j, rows, columns, matrix);
        }
    }

    printf("%d\n", max >= 0 ? max : 0);
    return 0;
}
