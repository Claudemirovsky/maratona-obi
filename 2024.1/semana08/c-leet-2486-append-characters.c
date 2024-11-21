#include <string.h>

int appendCharacters(char *s, char *t) {
    int count = strlen(t);
    while (*s && *t) {
        if (*s == *t) {
            count--;
            t++;
        }
        s++;
    }

    return count;
}
