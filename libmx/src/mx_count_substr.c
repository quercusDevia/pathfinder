#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -1;
    }

    if (*sub == '\0') {
        return 0;
    }

    int subCount = 0;

    int i = 0;
    while (str[i] != '\0') {
        int j = 0;

        while (sub[j] != '\0') {
            if (str[i] != sub[j]) {
                break;
            }
            i++;
            j++;
        }

        if (sub[j] == '\0') {
            subCount++;
        }
        else {
            i -= j - 1;
        }
    }

    return subCount;
}
