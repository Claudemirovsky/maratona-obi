#include <stdio.h>

int main() {
    int sports, arts, science, score;
    scanf("%d %d %d", &sports, &arts, &science);

    score = (sports * 2) + (arts * 3) + (science * 5);
    printf("%c\n", (score >= 200)   ? 'O'
                   : (score >= 150) ? 'S'
                   : (score >= 100) ? 'B'
                                    : 'N');
    return 0;
}
