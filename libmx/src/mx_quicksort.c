#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL) {
        return -1;
    }

    int swapCount = 0;

    int beg = left;
    int end = right;

    char* mid = arr[(beg + end) / 2];
    char* tmpr;

    while (beg <= end) {
        while (mx_strlen(mid) > mx_strlen(arr[beg])) {
            beg++;
        }

        while (mx_strlen(arr[end]) > mx_strlen(mid)) {
            end--;
        }

        if (beg <= end) {
            tmpr = arr[beg];
            arr[beg] = arr[end];
            arr[end] = tmpr;

            beg++;
            end--;

            swapCount++;
        }
    }

    if (left < end) {
        swapCount += mx_quicksort(arr, left, end);
    }

    if (right > beg) {
        swapCount += mx_quicksort(arr, beg, right);
    }

    return swapCount;
}
