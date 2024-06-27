#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (list == NULL) {
        return;
    }

    t_list *tmpr = *list;

    t_list *newNode = mx_create_node(data);

    if (*list == NULL) {
        *list = newNode;
        return;
    }

    while ((*list)->next != NULL) {
        *list = (*list)->next;
    }

    (*list)->next = newNode;
    *list = tmpr;
}
