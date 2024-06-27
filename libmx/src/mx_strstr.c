#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int i = 0;
    while (haystack[i] != '\0') {
        int j = i;
        int k = 0;

        while (needle[k] != '\0') {
            if (haystack[j] != needle[k]) {
                break;
            }
            j++;
            k++;
        }

        if (needle[k] == '\0') {
            return (char*)&(haystack[i]);
        }
        i++;
    }

    return NULL;
}
