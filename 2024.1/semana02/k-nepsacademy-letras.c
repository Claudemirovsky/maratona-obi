#include <stdio.h>

int main() {
    char target = getchar(), skip = 0, current, isinfec = 0, add = 0;
    double total_words = 0, infected_words = 0;
    getchar();

    while ((current = getchar()) != EOF && current != '\n') {
        if (current == ' ') {
            isinfec = 0;
            skip = 0;
            add = 0;
            continue;
        }
        if (skip)
            continue;
        if (!add) {
            total_words++;
            add = 1;
        }
        if (current == target)
            isinfec = 1;

        if (isinfec) {
            infected_words++;
            skip = 1;
            add = 0;
        }
    }

    if (total_words == 0 || infected_words == 0)
        printf("0.0\n");
    else
        printf("%.1lf\n", (infected_words / total_words) * 100.0);
    return 0;
}
