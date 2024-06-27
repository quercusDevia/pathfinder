#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    if (list == NULL) {
        return;
    }

    t_list *newNode = mx_create_node(data);

    newNode->next = *list;
    *list = newNode;
}
