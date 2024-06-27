#include "libmx.h"

unsigned long mx_powSpec(unsigned int n, unsigned int pow) {
    unsigned long num = 1;

    for (unsigned int i = 0; i < pow; i++) {
        num *= n;
    }

    return num;
}
