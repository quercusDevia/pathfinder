#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char *tmpr = dst;
    int lettCount = 0;

    while (*src != '\0' && lettCount < len) {
        *tmpr = *src;
        src++;
        tmpr++;

        lettCount++;
    }

    while (lettCount < len) {
        *tmpr = '\0';
        tmpr++;

        lettCount++;
    }

    return dst;
}
