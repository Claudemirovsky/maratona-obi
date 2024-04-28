#include <stdio.h>

void calc(char item, unsigned *acc, unsigned *max) {
    if (item == 'o')
        *acc = *acc + 1;
    if (*acc > *max)
        *max = *acc;
    if (item == 'A')
        *acc = 0;
}

int main() {
    unsigned tam, linha, coluna, max = 0, acc = 0;
    scanf("%u", &tam);
    char matriz[tam][tam];

    for (linha = 0; linha < tam; linha++) {
        getchar(); // \n
        for (coluna = 0; coluna < tam; matriz[linha][coluna++] = getchar())
            ;
    }

    for (linha = 0; linha < tam; linha++) {
        if ((linha & 1) == 0) {
            for (coluna = 0; coluna < tam;
                 calc(matriz[linha][coluna++], &acc, &max))
                ;
        } else {
            for (coluna = tam; coluna > 0;
                 calc(matriz[linha][--coluna], &acc, &max))
                ;
        }
    }

    printf("%u\n", max);
    return 0;
}
