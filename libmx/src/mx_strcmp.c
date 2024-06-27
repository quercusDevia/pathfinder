#include "libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    int chNum = 0;

    while (s1[chNum] != '\0' && s2[chNum] != '\0') {
        if (s1[chNum] != s2[chNum]) {
            break;
        }

        chNum++;
    }

    return s1[chNum] - s2[chNum];
}
