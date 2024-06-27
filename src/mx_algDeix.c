#include "pathfinder.h"

short** mx_algDeix(int* islands, int** bridges, int num, short ind) {
    short** path = malloc(num * sizeof(short*));

    for(int i = 0; i < num; i++) {
        path[i] = malloc(2 * sizeof(short));
        path[i][0] = -2;
        path[i][1] = -1;
    }
    path[ind][0] = ind;

    ////////////////////////////////////////
    short* visited = malloc(num * sizeof(short));

    for(int i = 0; i < num; i++) {
        visited[i] = 0;
    }

    ////////////////////////////////////////
    visited[ind] = 1;
    short current = ind;

    for(int i = 0; i < num; i++) {
        if(bridges[ind][i] != -1) {
            islands[i] = bridges[ind][i];
            path[i][0] = ind;
        }
    }

    ////////////////////////////////////////
    for(int i = 0; i < num - 1; i++) {
        for(int j = 0; j < num; j++) {
            if(visited[j] != 1) {
                current = j;
                break;
            }
        }

        for(int j = 0; j < num; j++) {
            if(visited[j] != 1 && islands[j] < islands[current]) {
                current = j;
            }
        }

        /////////////////////////////////////////
        visited[current] = 1;

        /////////////////////////////////////////
        for(int j = 0; j < num; j++) {
            if(visited[j] == 1 || bridges[current][j] == -1) {
                continue;
            }

            int forkSize = 2;
            while(path[j][forkSize - 1] != -1) {
                forkSize++;
            }

            if(islands[current] + bridges[current][j] < islands[j]) {
                islands[j] = islands[current] + bridges[current][j];

                if(forkSize != 2) {
                    path[j] = mx_realloc(path[j], 2);

                    path[j][1] = -1;
                }
                
                path[j][0] = current;
                continue;
            }

            if(islands[current] + bridges[current][j] == islands[j]) {
                path[j] = mx_realloc(path[j], ++forkSize);

                path[j][forkSize - 1] = -1;
                path[j][forkSize - 2] = current;
            }
        }
    }

    free(visited);

    return path;
}
