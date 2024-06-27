#include "pathfinder.h"

short* mx_toFormPath(int fromInd, int toInd, short** path, short* pathInds) {
    int size = 0;
    for(int i = toInd; path[i][pathInds[i]] != fromInd; i = path[i][pathInds[i]]) {
        size++;
    }

    short* formPath = malloc((size + 3) * sizeof(short));

    formPath[0] = fromInd;
    formPath[size + 1] = toInd;
    formPath[size + 2] = -1;

    for(int i = toInd; path[i][pathInds[i]] != fromInd; i = path[i][pathInds[i]], size--) {
        formPath[size] = path[i][pathInds[i]];
    }

    return formPath;
}
