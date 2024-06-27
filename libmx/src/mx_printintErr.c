#include "libmx.h"

void mx_printintErr(int n) {
    if (n < 0) {
        mx_printcharErr('-');
    }
    else if (n == 0) {
        mx_printcharErr('0');
        return;
    }

    int num = n;
    int digCount = 0;

    while (num != 0) {
        digCount++;
        num /= 10;
    }

    for (int i = digCount; i > 0; i--) {
        num = n;

        for (int j = 0; j < (i - 1); j++) {
            num /= 10;
        }

        num %= 10;

        if (num >= 0) {
            mx_printcharErr((char)(num + 48));
        }
        else {
            mx_printcharErr((char)(-num + 48));
        }
    }

    return;
}
