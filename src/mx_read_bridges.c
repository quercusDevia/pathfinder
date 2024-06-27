#include "pathfinder.h"

int mx_read_bridges(int** bridges, char** names, int num, int fd) {
    int lineCounter = 2;
    int islCounter = 0;

    unsigned int sum = 0;
    char* temp = NULL;
    ////////////////////////////////////////////

    int statusHl = mx_safe_read(&temp, '-', fd);

    while(statusHl) {
        if(mx_check_name(temp) == -1) {
            statusHl = lineCounter;
            break;
        }

        int n = 0;
        for(; n < islCounter; n++) {
            if(mx_strcmp(temp, names[n]) == 0) {
                break;
            }
        }

        if(n == islCounter) {
            islCounter++;

            if(islCounter > num) {
                statusHl = -6;
                break;
            }

            names[n] = temp;
        }

        temp = NULL;

        ////////////////////////////////////////////////////
        statusHl = mx_safe_read(&temp, ',', fd);

        if(mx_check_name(temp) == -1) {
            statusHl = lineCounter;
            break;
        }

        int m = 0;
        for(; m < islCounter; m++) {
            if(mx_strcmp(temp, names[m]) == 0) {
                break;
            }
        }

        if(m == islCounter) {
            islCounter++;

            if(islCounter > num) {
                statusHl = -6;
                break;
            }

            names[m] = temp;
        }

        temp = NULL;

        ////////////////////////////////////////////////////
        statusHl = mx_safe_read(&temp, '\n', fd);

        unsigned int lenOfBr = mx_strToUnsNumber(temp);
        mx_strdel(&temp);

        if(lenOfBr < 1) {
            statusHl = lineCounter;
            break;
        }

        sum += lenOfBr;

        ////////////////////////////////////////////////////
        if(m == n) {
            statusHl = lineCounter;
            return lineCounter;
        }

        if(bridges[m][n] != -1) {
            statusHl = -7;
            break;
        }

        if(sum > INT_MAX) {
            statusHl = -8;
            break;
        }

        bridges[m][n] = lenOfBr;
        bridges[n][m] = lenOfBr;

        lineCounter++;

        statusHl = mx_safe_read(&temp, '-', fd);
    }
    mx_strdel(&temp);

    if(statusHl != 0) {
        return statusHl;
    }

    if(islCounter < num) {
        return -6;
    }

    return 0;
}
