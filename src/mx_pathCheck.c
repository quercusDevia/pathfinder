#include "pathfinder.h"

int mx_pathCheck(int from, int to, short** path) {
    while(path[to][0] != from) {
        if(path[to][0] == -2) {
            return -1;
        }

        to = path[to][0];
    }

    return 0;
}
