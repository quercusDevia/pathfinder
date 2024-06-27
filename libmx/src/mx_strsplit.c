#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    int num = mx_count_words(s, c);

    if (num == 0) {
        return NULL;
    }

    char** strArr = malloc((num + 1) * sizeof(char*));

    int i = 0;
    int j = 0;

    while (s[j] != '\0') {
        while (s[j] == c) {
            j++;
        }

        int len = 0;
        while (s[j + len] != '\0' && s[j + len] != c) {
            len++;
        }

        strArr[i] = mx_strndup((const char*)&(s[j]), len);
        j += len;
        i++;
    }

    strArr[i] = NULL;

    return strArr;
}
