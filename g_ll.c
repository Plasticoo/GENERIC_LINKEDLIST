#include "g_ll.h"

#include <stdlib.h>

void gll_push_top(struct gll_node **head, void *data, size_t data_size) {
    int i;
    struct gll_node *new_node = malloc(sizeof(struct gll_node));

    new_node->data  = malloc(data_size);
    new_node->next = (*head);

    for (i = 0; i < (int)data_size; i++) {
        *(char *)(new_node->data + i) = *(char *)(data + i);
    }

    (*head) = new_node;
}

void gll_push_end(struct gll_node *head, void *data, size_t data_size) {
    int i;
    struct gll_node *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct gll_node));
    current->next->data = malloc(data_size);
    current->next->data = NULL;

    for (i = 0; i < (int)data_size; i++) {
        *(char*)(current->next->data + i) = *(char*)(data + i);
    }
}

void gll_print(struct gll_node *head, void (*pfnct)(void*)) {
    return;
}
