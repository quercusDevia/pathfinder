#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (head == NULL || *head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *tmprNode = *head;

    while ((*head)->next->next != NULL) {
        *head = (*head)->next;
    }

    t_list *newEnd = *head;
    *head = (*head)->next;

    free(*head);
    newEnd->next = NULL;

    *head = tmprNode;
}
