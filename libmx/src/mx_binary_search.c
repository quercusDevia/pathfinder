#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;
    int mid;

    int res;
    while (left <= right) {
        (*count)++;
        
        mid = left + (right - left) / 2;
        res = mx_strcmp((const char*)s, (const char*)arr[mid]);

        if (res == 0)
        {
            return mid;
        }
        else if (res > 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    (*count) = 0;
    return -1;
}
