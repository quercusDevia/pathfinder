#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (lineptr == NULL || buf_size == 0 || fd < 0) {
        return -2;
    }

    //////////////////////////////////////////////////////
    int bytes = 0;
    bool isEmpty = true;

    static char* savStr = NULL;
    int savStrLen = 0;

    int bytesFrmStr = 0;
    if (savStr != NULL) {
        isEmpty = false;

        savStrLen = mx_strlen(savStr);
        bytesFrmStr = mx_get_char_index(savStr, delim);

        if (bytesFrmStr == -1) {
            mx_strdel(lineptr);
            *lineptr = mx_strdup(savStr);

            mx_strdel(&savStr);

            bytesFrmStr = savStrLen;
        }
        else {
            mx_strdel(lineptr);
            *lineptr = mx_strndup(savStr, bytesFrmStr);

            savStr = mx_memmove(savStr, &(savStr[bytesFrmStr]), savStrLen - bytesFrmStr);
            savStr = mx_realloc(savStr, savStrLen - bytesFrmStr + 1);
            savStr[savStrLen - bytesFrmStr] = '\0';

            return bytesFrmStr;
        }
    }

    bytes += bytesFrmStr;

    ////////////////////////////////////////////////////////

    char* newBuf = malloc(buf_size);

    int bytesFrmFl = read(fd, newBuf, buf_size);

    if (bytesFrmFl == -1) {
        mx_strdel(&newBuf);
        return -2;
    }

    while(bytesFrmFl) {
        isEmpty = false;

        int bytesFrmBuf = 0;
        for (; bytesFrmBuf < bytesFrmFl; bytesFrmBuf++) {
            if (newBuf[bytesFrmBuf] == delim) {
                break;
            }
        }

        *lineptr = mx_realloc(*lineptr, bytes + bytesFrmBuf + 1);
        mx_strncpy(&((*lineptr)[bytes]), newBuf, bytesFrmBuf);

        bytes += bytesFrmBuf;

        (*lineptr)[bytes] = '\0';

        if ((size_t)bytesFrmBuf != buf_size) {
            savStr = mx_strndup(&(newBuf[bytesFrmBuf]), bytesFrmFl - bytesFrmBuf);

            mx_strdel(&newBuf);
            return bytes;
        }

        bytesFrmFl = read(fd, newBuf, buf_size);
    }

    mx_strdel(&newBuf);

    if (isEmpty) {
        return -1;
    }

    return bytes;    
}
