void reverseString(char *s, int sSize) {
    for (int start = 0, end = sSize - 1; start < end; start++, end--) {
        s[start] ^= s[end];
        s[end] ^= s[start];
        s[start] ^= s[end];
    }
}

// Just for testing
#include <malloc.h>
#include <stdio.h>

int main() {
    char *str = NULL;
    size_t num;
    int size = getline(&str, &num, stdin);
    if (str == NULL) {
        printf("Error while reading string from stdin. aborting.");
        return 1;
    }
    if (str[size - 1] == '\n')
        str[--size] = 0;

    printf("%s -> ", str);
    reverseString(str, size);
    printf("%s\n", str);
    free(str);
    return 0;
}
