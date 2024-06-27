#include "pathfinder.h"

int pathComp(short* p1, short* p2) {
    int i = 0;
    for(; p1[i] != -1 && p2[i] != -1; i++) {
        if(p1[i] != p2[i]) {
            break;
        }
    }

    return p1[i] - p2[i];
}

void mx_sortPath(short** formPathes, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(pathComp(formPathes[j], formPathes[j + 1]) > 0) {
                short* temp = formPathes[j];
                formPathes[j] = formPathes[j + 1];
                formPathes[j + 1] = temp;
            }
        }
    }
}
