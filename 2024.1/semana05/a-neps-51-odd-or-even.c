#include <stdio.h>

int main() {
    int choice, a, b;
    scanf("%d %d %d", &choice, &a, &b);
    a = (a + b) & 1;
    printf("%d\n", choice ^ a);
    return 0;
}
