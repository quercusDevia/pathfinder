#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    char *newStr = mx_strnew(mx_strlen(str));

    int i = 0;
    int j = 0;
    
    while (str[i] <= 32 && str[i] > 0) {
        i++;
    }

    while (str[i] > 32) {
        newStr[j++] = str[i++];
    }    
    
    while (str[i] != '\0') {
        while(str[i] <= 32 && str[i] > 0) {
            i++;
        }

        if (str[i] != '\0') {
            newStr[j++] = ' ';
        }

        while (str[i] > 32) {
            newStr[j++] = str[i++];
        }
    }

    char* newNewStr = mx_strdup((const char*)newStr);
    mx_strdel(&newStr);

    return newNewStr;
}
