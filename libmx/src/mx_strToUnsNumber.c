#include "libmx.h"

unsigned int mx_strToUnsNumber(char* str) {
    if(str == NULL) {
        return 0;
    }

    unsigned int num = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] < 48 || str[i] > 57) {
            return 0;
        }

        num *= 10;
        num += str[i] - 48;
    }

    return num;
}
