#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char* tmprBig = (unsigned char*)big;
    unsigned char* tmprLittle = (unsigned char*)little;

    size_t i = 0;

    for (; i < big_len; i++) {
        size_t k = 0;

        for (; k < little_len; k++) {
            if (tmprBig[i] != tmprLittle[k]) {
                break;
            }

            i++;
        }

        i -= k;

        if(k == little_len) {
            return (void*)&((unsigned char*)tmprBig)[i];
        }
    }

    return NULL;
}
