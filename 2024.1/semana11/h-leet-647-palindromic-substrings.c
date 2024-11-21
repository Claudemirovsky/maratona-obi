#include <string.h>

int countSubstrings(char *s) {
    int len = strlen(s);
    int res = 0;

    for (int i = 0; i < len; ++i) {
        int l = i, r = i + 1;
        while (l >= 0 && r < len && s[l--] == s[r++])
            res++;

        l = i - 1;
        r = i + 1;

        while (l >= 0 && r < len && s[l--] == s[r++])
            res++;
    }

    return res + len;
}
