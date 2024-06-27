#include "pathfinder.h"

int mx_count_islands(int fd) {
    char* str = NULL;
    int status = mx_safe_read(&str, '\n', fd);

    if(status == 0) {
        return -1;
    }
    if(status == -1) {
        return -2;
    }

    int len = mx_strlen(str);

    int num = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] < 48 || str[i] > 57) {
            mx_strdel(&str);
            return -2;
        }

        num *= 10;
        num += str[i] - 48;
    }

    mx_strdel(&str);
    return num;
}
