#include "libmx.h"

int mx_safe_read(char** lineptr, char delim, int fd) {
    if(fd < 1 || lineptr == NULL) {
        return -2;
    }

    int len = 0;
    if(*lineptr != NULL) {
        len = mx_strlen(*lineptr);
    }
    len++;

    char buf[1] = {"\0"};
    int bytes = read(fd, buf, 1);
    int status = 0;

    while(bytes != 0 && buf[0] != delim) {
        *lineptr = mx_realloc(*lineptr, ++len);
        (*lineptr)[len - 2] = buf[0];
        (*lineptr)[len - 1] = '\0';

        status = 1;
        bytes = read(fd, buf, 1);
    }

    if(status == 0 && buf[0] == delim) {
        return -1;
    }

    return status;
}
