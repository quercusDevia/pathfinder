#include "libmx.h"

void mx_str_reverse(char *s) {
    if (s == NULL) {
        return;
    }

    int len = mx_strlen((const char*)s);
    int hLen = len / 2;

    for (int i = 0; i < hLen; i++) {
        mx_swap_char(&s[i], &s[len - i - 1]);
    }
}
