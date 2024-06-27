#include "pathfinder.h"

void mx_printPath(int fromInd, int toInd, short* formPath, int** bridges, int* rowOfIslands, char** names) {
    ////////////////////////Path//////////////////////////////
    mx_printstr("========================================");

    mx_printstr("\nPath: ");
    mx_printstr(names[fromInd]);
    mx_printstr(" -> ");
    mx_printstr(names[toInd]);

    ///////////////////////Route//////////////////////////////
    mx_printstr("\nRoute: ");

    for(int i = 0; formPath[i + 1] != -1; i++) {
        mx_printstr(names[formPath[i]]);
        mx_printstr(" -> ");
    }

    mx_printstr(names[toInd]);

    //////////////////////Distance////////////////////////////
    mx_printstr("\nDistance: ");

    int i = 0;
    for(; formPath[i + 2] != -1; i++) {
        mx_printint(bridges[formPath[i]][formPath[i + 1]]);
        mx_printstr(" + ");
    }

    if(i != 0) {
        mx_printint(bridges[formPath[i]][formPath[i + 1]]);
        mx_printstr(" = ");
    }
    mx_printint(rowOfIslands[toInd]);

    mx_printstr("\n========================================\n");    
}
