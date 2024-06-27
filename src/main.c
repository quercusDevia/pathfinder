#include "pathfinder.h"

int main(int argc, char** argv) {
    if(argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 0;
    }

    /////////////////////////////////////////////////
    int fd = open(argv[1], O_RDONLY);

    if(fd == -1) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        return 0;
    }

    int num = mx_count_islands(fd);

    if(num == -1) {
        close(fd);
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        return 0;
    }

    if(num < 1) {
        close(fd);
        mx_printerr("error: line 1 is not valid\n");
        return 0;
    }

    /////////////////////////////////////////////////
    int** bridges = malloc(num * sizeof(int*));

    for(int i = 0; i < num; i++) {
        bridges[i] = malloc(num * sizeof(int));

        for(int j = 0; j < num; j++) {
            bridges[i][j] = -1;
        }
    }

    char** nameOfBrid = malloc((num + 1) * sizeof(char*));

    for(int i = 0; i <= num; i++) {
        nameOfBrid[i] = NULL;
    }

    /////////////////////////////////////////////////
    int status = mx_read_bridges(bridges, nameOfBrid, num, fd);
    
    close(fd);

    if(status != 0) {
        mx_delBigIntArr(&bridges, num);
        mx_del_strarr(&nameOfBrid);

        switch(status) {
        case -6:
            mx_printerr("error: invalid number of islands\n");
            return 0;
        case -7:
            mx_printerr("error: duplicate bridges\n");
            return 0;
        case -8:
            mx_printerr("error: sum of bridges lengths is too big\n");
            return 0;
        default:
            mx_printerr("error: line ");
            mx_printintErr(status);
            mx_printerr(" is not valid\n");
            return 0;
        }
    }

    /////////////////////////////////////////////////////////////////
    int** islands = malloc(num * sizeof(int*));

    for(int i = 0; i < num; i++) {
        islands[i] = malloc(num * sizeof(int));

        for(int j = 0; j < num; j++) {
            if(i == j) {
                islands[i][j] = 0;
                continue;
            }

            islands[i][j] = INT_MAX;
        }
    }

    /////////////////////////////////////////////////////////////
    short** path;

    for(int i = 0; i < num - 1; i++) {
        path = mx_algDeix(islands[i], bridges, num, i);

        mx_bridgeOutput(i, num, islands[i], bridges, path, nameOfBrid);

        mx_delBigShortArr(&path, num);
    }

    /////////////////////////////////////////////////////////////
    mx_delBigIntArr(&bridges, num);
    mx_delBigIntArr(&islands, num);
    mx_del_strarr(&nameOfBrid);
}
