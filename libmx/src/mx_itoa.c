#include "libmx.h"

char *mx_itoa(int number) {
    char *str;

    if (number == 0) {
        str = mx_strnew(1);
        str[0] = '0';
        return str;
    }

    int tmpr = number;
    int lettCount = 0;

    while (tmpr != 0) {
        tmpr /= 10;
        lettCount++;
    }

    int isNeg = 1;

    if (number < 0) {
        lettCount++;

        str = mx_strnew(lettCount);
        str[0] = '-';

        isNeg = -1;
    }
    else {
        str = mx_strnew(lettCount);
    }

    while(number != 0) {
        str[lettCount - 1] = isNeg * (number % 10) + 48;
        number /= 10;
        lettCount--;
    }

    return str;
}
