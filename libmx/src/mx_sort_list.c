#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    int size = mx_list_size(lst);

    if(size < 2) {
        return lst;
    }

    t_list *frstNode = lst;
    t_list *tmpr1 = NULL;
    t_list *tmpr2 = NULL;

    for (int i = size - 1; i > 0; i--) {
        lst = frstNode;
        int j = 1;

        if (cmp(lst->data, lst->next->data)) {
            tmpr1 = lst;
            tmpr2 = lst->next->next;

            lst = lst->next;
            lst->next = tmpr1;
            lst->next->next = tmpr2;

            frstNode = lst;
        }

        for (; j < i; j++) {
            if (cmp(lst->next->data, lst->next->next->data)) {
                tmpr1 = lst->next;
                tmpr2 = lst->next->next->next;

                lst->next = lst->next->next;
                lst = lst->next;
                lst->next = tmpr1;
                lst->next->next = tmpr2;
            }
        }
    }

    return frstNode;
}
