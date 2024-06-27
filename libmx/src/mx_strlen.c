#include "libmx.h"

int mx_strlen(const char *s) {
    char *str = (char *)s;
    int counter = 0;

    while (*str != '\0') {
        counter++;
        str++;
    }

    return counter;
}
