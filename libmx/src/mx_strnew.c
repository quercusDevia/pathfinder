#include "libmx.h"

char *mx_strnew(const int size) {
    if (size < 0) {
        return NULL;
    }

    char *smth = malloc(size + 1);

    for (int i = 0; i <= size; i++) {
        smth[i] = '\0';
    }
    
    return smth;
}
