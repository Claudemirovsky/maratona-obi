#include <string.h>

char *getEncryptedString(char *s, int k) {
    int len = strlen(s);
    char temp[len + 1];
    temp[len] = 0;
    for (int i = 0; i < len; ++i)
        temp[i] = s[(i + k) % len];
    strcpy(s, temp);
    return s;
}
