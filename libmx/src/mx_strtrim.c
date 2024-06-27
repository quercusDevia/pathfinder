#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int startOfStr = 0;
    int endOfStr = mx_strlen(str) - 1;

    while((str[startOfStr] <= 32 && str[startOfStr] > 0) && startOfStr < endOfStr) {
        startOfStr++;
    }

    while((str[endOfStr] <= 32 && str[endOfStr] > 0) && endOfStr >= startOfStr) {
        endOfStr--;
    }

    if (startOfStr > endOfStr) {
        return NULL;
    }

    int len = endOfStr - startOfStr + 1;

    char* newStr = mx_strnew(len);
    newStr = mx_strncpy(newStr, &(str[startOfStr]), len);

    return newStr;
}
