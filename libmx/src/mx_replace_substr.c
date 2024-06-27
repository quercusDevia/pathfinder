#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) {
        return NULL;
    }

    int num = mx_count_substr(str, sub);
    int subLen = mx_strlen(sub);
    int sizeAdd = (mx_strlen(replace) - subLen) * num;

    char* newStr = mx_strnew(mx_strlen(str) + sizeAdd);

    int i = 0;
    int j = 0;
    int k = mx_get_substr_index(str, sub);

    while (i < k) {
        newStr[i] = str[i];
        i++;
    }

    j = i;

    for (int n = 0; n < num; n++) {
        int m = 0;
        while (replace[m] != '\0') {
            newStr[j] = replace[m];
            j++;
            m++;
        }

        i += subLen;

        k = mx_get_substr_index(&(str[i]), sub) + i;

        while (i < k) {
            newStr[j] = str[i];
            j++;
            i++;
        }
    }

    while (str[i] != '\0') {
        newStr[j] = str[i];
        j++;
        i++;
    }

    return newStr;    
}
