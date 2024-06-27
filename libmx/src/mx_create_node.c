#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *smth = malloc(sizeof(t_list));

    if (!smth) {
        return 0;
    }

    smth->data = data;
    smth->next = NULL;

    return smth;
}
