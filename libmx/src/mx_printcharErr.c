#include "libmx.h"

void mx_printcharErr(char c) {
    write(2, &c, 1);
}
