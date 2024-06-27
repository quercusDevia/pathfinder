#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }

    char *newStr; 

    if (s1 == NULL) {
        newStr = mx_strdup((const char*)s2);
        return newStr;
    }

    if (s2 == NULL) {
        newStr = mx_strdup((const char*)s1);
        return newStr;
    }

    int len1 = mx_strlen((const char*)s1);
    int len2 = mx_strlen((const char*)s2);

    newStr = mx_strnew(len1 + len2);

    mx_strncpy(newStr, s1, len1);
    mx_strncpy(&(newStr[len1]), s2, len2);

    return newStr;
}
