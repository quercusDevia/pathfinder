#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if (n < 1) {
        return 0;
    }

    size_t i = 0;
    for (; i < n; i++) {
        if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i]) {
            break;
        }
    }

    return ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i];
}
