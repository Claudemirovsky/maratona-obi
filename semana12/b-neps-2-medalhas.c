#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int main() {
    int first, second, third;
    scanf("%d %d %d", &first, &second, &third);
    int b = max(max(first, second), third), m = min(min(first, second), third);

    printf("%d\n", m == first ? 1 : m == second ? 2 : 3);
    printf("%d\n", m != first && b != first     ? 1
                   : m != second && b != second ? 2
                                                : 3);
    printf("%d\n", b == first ? 1 : b == second ? 2 : 3);
    return 0;
}
