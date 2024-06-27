#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        return NULL;
    }

    int len = 0;
    char buf[1];
    int stat = read(fd, buf, 1);

    while (stat == 1) {
        len++;
        stat = read(fd, buf, 1);
    }

    stat = close(fd);
    fd = open(file, O_RDONLY);

    if (fd == -1) {
        return NULL;
    }

    char* str = mx_strnew(len);

    stat = read(fd, buf, 1);

    int i = 0;
    while (stat == 1) {
        str[i] = *buf;
        i++;
        stat = read(fd, buf, 1);
    }

    close(fd);

    return str;
}
