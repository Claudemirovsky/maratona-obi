/* beecrowd - 2417 */
#include <stdio.h>

#define fetch(team)                                                            \
    scanf("%hd%hd%hd", &pontos_##team, &aux, &gols_##team);                    \
    pontos_##team *= 3;                                                        \
    pontos_##team += aux

int main() {
    short aux, gols_cor, pontos_cor = 0, gols_fla, pontos_fla = 0;
    fetch(cor);
    fetch(fla);
    char empate = pontos_cor == pontos_fla;

    if (pontos_cor > pontos_fla || (empate && gols_cor > gols_fla))
        puts("C");
    else if (pontos_fla > pontos_cor || (empate && gols_fla > gols_cor))
        puts("F");
    else
        puts("=");

    return 0;
}
