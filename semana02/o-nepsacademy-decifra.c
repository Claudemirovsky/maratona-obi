#include <stdio.h>

int main() {
    char chave[26] = {0}, index, ch;

    for (index = 0; index < 26; chave[index++] = getchar())
        ;

    getchar();
    while ((ch = getchar()) != EOF && ch != '\n') {
        putchar(chave[ch - 'a']);
    }

    putchar('\n');
    return 0;
}
