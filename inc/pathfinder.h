#ifndef MX_PATHFINDER
#define MX_PATHFINDER

#include "libmx.h"
#include <limits.h>

int mx_count_islands(int fd);
int mx_read_bridges(int** bridges, char** names, int num, int fd);
int mx_check_name(char* str);
short** mx_algDeix(int* islands, int** bridges, int num, short ind);
void mx_bridgeOutput(int startInd, int num, int* rowOfIslands, int** bridges, short** path, char** names);
void mx_printPath(int fromInd, int toInd, short* formPath, int** bridges, int* rowOfIslands, char** names);
short findLastFork(int fromInd, int toInd, short** path, short* pathInds);
int mx_pathCheck(int from, int to, short** path);
short* mx_toFormPath(int fromInd, int toInd, short** path, short* pathInds);
void mx_sortPath(short** formPathes, int size);

#endif
