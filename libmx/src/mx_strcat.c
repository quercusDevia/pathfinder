#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    if (s2 == NULL) {
        return s1;
    }

    int i = 0;
    while (s1[i] != '\0') {
        i++;
    }

    int j = 0;
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';

    return s1;
}
