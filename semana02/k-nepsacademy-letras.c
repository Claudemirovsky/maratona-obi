// #include <fenv.h> // Necessário pra arredondar pra baixo no printf
#include <stdio.h>

int main() {
    char target = getchar(), skip = 0, current, isinfec = 0;
    double total_words = 0, infected_words = 0, chars = 0;
    getchar();

    while ((current = getchar()) != EOF && current != '\n') {
        if (current == ' ') {
            chars = 0;
            isinfec = 0;
            skip = 0;
            continue;
        }
        if (skip)
            continue;
        chars++;
        if (current == target)
            isinfec = 1;

        if (chars == 2)
            total_words++;
        if (isinfec && chars >= 2) {
            infected_words++;
            skip = 1;
        }
    }

    // fesetround(FE_DOWNWARD); // Necessário pra arredondar pra baixo no printf
    if (total_words == 0 || infected_words == 0)
        printf("0.0\n");
    else
        printf("%.1lf\n", (infected_words / total_words) * 100.0);
    return 0;
}
