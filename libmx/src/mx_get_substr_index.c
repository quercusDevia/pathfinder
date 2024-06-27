#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {

    if (str == NULL || sub == NULL) {
        return -2;
    }

    int i = 0;
    while (str[i] != '\0') {
        int j = i;
        int k = 0;

        while (sub[k] != '\0') {
            if (str[j] != sub[k]) {
                break;
            }
            j++;
            k++;
        }

        if (sub[k] == '\0') {
            return i;
        }
        i++;
    }

    return -1;
}
