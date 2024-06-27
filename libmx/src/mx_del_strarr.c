#include "libmx.h"

void mx_del_strarr(char ***arr) {
    if(*arr == NULL || arr == NULL) {
        return;
    }

    char** tmpr = *arr;

    int i = 0;
    while(tmpr[i] != NULL) {
        mx_strdel(&(tmpr[i]));
        i++;
    }

    free(tmpr);
    *arr = NULL;
}
