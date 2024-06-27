#include "libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *tmpr = dst;

    while (*src != '\0') {
        *tmpr = *src;
        src++;
        tmpr++;
    }
    *tmpr = '\0';

    return dst;
}
