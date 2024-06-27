#include "pathfinder.h"

int mx_check_name(char* str) {
    if(str == NULL) {
        return -1;
    }

    int i = 0;
    while(str[i] != '\0') {
        if(str[i] < 65 || str[i] > 122 || (str[i] > 90 && str[i] < 97)) {
            return -1;
        }
        i++;
    }

    return 0;
}
