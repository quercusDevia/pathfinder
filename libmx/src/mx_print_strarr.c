#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int i = 0;

    if (arr == NULL || arr[i] == NULL || delim == NULL) {
        return;
    }

    mx_printstr((const char*)arr[i]);
    i++;

    while (arr[i] != NULL) {
        mx_printstr(delim);
        mx_printstr(arr[i]);
        i++;
    }

    mx_printchar('\n');
}
