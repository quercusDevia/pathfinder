#include "pathfinder.h"

void mx_bridgeOutput(int startInd, int num, int* rowOfIslands, int** bridges, short** path, char** names) {
    short* pathInds = malloc(num * sizeof(short));
    for(int i = 0; i < num; i++) {
        pathInds[i] = 0;
    }

    int pathCounter = 0;
    short** formPathes;
    
    for(int i = startInd + 1, k = 0; i < num; i++, k = 0, pathCounter = 0) {
        if(mx_pathCheck(startInd, i, path) == -1) {
            continue;
        }

        short temp = findLastFork(startInd, i, path, pathInds);
        pathCounter++;

        while(temp != -1) {
            for(int j = path[temp][pathInds[temp]], last = j; j != startInd;) {
                pathInds[last] = 0;

                last = j;
                j = path[j][pathInds[j]];
            }

            pathInds[temp]++;

            temp = findLastFork(startInd, i, path, pathInds);
            pathCounter++;
        }

        for(int j = 0; j < num; j++) {
            pathInds[j] = 0;
        }

        ///////////////////////////////////////////////////////////////
        formPathes = malloc(pathCounter * sizeof(short*));

        temp = findLastFork(startInd, i, path, pathInds);
        formPathes[k++] = mx_toFormPath(startInd, i, path, pathInds);

        while(temp != -1) {
            for(int j = path[temp][pathInds[temp]], last = j; j != startInd;) {
                pathInds[last] = 0;

                last = j;
                j = path[j][pathInds[j]];
            }

            pathInds[temp]++;

            temp = findLastFork(startInd, i, path, pathInds);
            formPathes[k++] = mx_toFormPath(startInd, i, path, pathInds);
        }

        for(int j = 0; j < num; j++) {
            pathInds[j] = 0;
        }

        mx_sortPath(formPathes, pathCounter);

        for(int j = 0; j < pathCounter; j++) {
            mx_printPath(startInd, i, formPathes[j], bridges, rowOfIslands, names);
        }

        mx_delBigShortArr(&formPathes, pathCounter);
    }

    free(pathInds);
}
