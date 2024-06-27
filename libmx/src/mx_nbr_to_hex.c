#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long tmpr = nbr;
    unsigned int arrSize = 0;

    while (tmpr != 0) {
        tmpr /= 16;
        arrSize++;
    }

    char *arr = NULL;

    if (arrSize == 0) {
        arr = mx_strnew(1);
        arr[0] = '0';
        return arr;
    }
    
    arr = mx_strnew(arrSize);

    tmpr = nbr;
    unsigned int lnum;

    for (int i = arrSize - 1; i >= 0; i--) {
        lnum = tmpr % 16;

        if (lnum < 10) {
            arr[i] = lnum + 48;
        }
        else {
            arr[i] = lnum + 87;
        }
        tmpr /= 16;
    }

    return arr;
}
