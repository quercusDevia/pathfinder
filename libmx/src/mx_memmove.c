#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char* tmpr = malloc(len);

    unsigned char* tmprSrc = (unsigned char*)src;
    unsigned char* tmprDst = (unsigned char*)dst;

    for (size_t i = 0; i < len; i++) {
        tmpr[i] = tmprSrc[i];
    }

    for (size_t i = 0; i < len; i++) {
        tmprDst[i] = tmpr[i];
    }

    free(tmpr);

    return dst;
}
