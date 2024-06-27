#include "pathfinder.h"

short findLastFork(int fromInd, int toInd, short** path, short* pathInds) {
    short temp = -1;

    for(int j = toInd; j != fromInd;) {//search
        if(path[j][pathInds[j] + 1] != -1) {
            temp = j;
        }

        j = path[j][pathInds[j]]; 
    }

    return temp;
}
