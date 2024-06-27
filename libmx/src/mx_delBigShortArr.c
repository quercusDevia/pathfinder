#include "libmx.h"

void mx_delBigShortArr(short*** arr, int m) {
    if(arr == NULL) {
        return;
    }

    for(int i = 0; i < m; i++) {
        free((*arr)[i]);
        (*arr)[i] = NULL;
    }
    
    free(*arr);
    *arr = NULL;
}
