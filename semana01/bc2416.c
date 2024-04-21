/* beecrowd - 2416 */
#include <stdio.h>

int main() {
    long metros_corridos, metros_pista;
    scanf("%ld%ld", &metros_corridos, &metros_pista);
    printf("%ld\n", metros_corridos % metros_pista);
    return 0;
}
