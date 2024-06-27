#include "libmx.h"

int mx_list_size(t_list *list) {
    int nodeCount = 0;

    while (list != NULL) {
        list = list->next;
        nodeCount++;
    }

    return nodeCount;
}
