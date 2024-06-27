#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (s1 == NULL || n == 0) {
        return NULL;
    }

    char *newStr = mx_strnew(n);
    newStr = mx_strncpy(newStr, s1, (int)n);
    
    return newStr;
}
