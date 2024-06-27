#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int swapCnt = 0;
    char *temp;
    
    for (int i = (size - 1); i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (mx_strcmp((const char*)arr[j], (const char*)arr[j - 1]) < 0) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;

                swapCnt++;
            }
        }
    }

    return swapCnt;
}
