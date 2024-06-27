#include "libmx.h"

int mx_sqrt(int x) {
    if (x < 0) {
        return 0;
    }

    unsigned int num = 0;
    unsigned int result = 0;

    for (; (result = num * num) <= (unsigned int)x; num++) {
        if (result == (unsigned int)x) {
            return num;
        }
    }
    
    return 0; 
}
