#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    char *tmpr = (char*)hex;
    int arrSize = mx_strlen(hex);
    
    int num = 0;
    unsigned long result = 0;

    for (int i = 0; i < arrSize; i++) {
        if (mx_isdigit(tmpr[i])) {
            num = tmpr[i] - 48;
        }
        else if (mx_isupperHexL(tmpr[i])) {
            num = tmpr[i] - 55;
        }
        else if (mx_islowerHexL(tmpr[i])) {
            num = tmpr[i] - 87;
        }
        else {
            return 0;
        }

        result += num * mx_powSpec(16, (arrSize - i - 1));
    }

    return result;
}
