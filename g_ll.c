#include "g_ll.h"

#include <stdlib.h>
#include <stdio.h>

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

void gll_pop_top(struct gll_node **head) {
    struct gll_node *new_head = NULL;

    if (*head == NULL) {
        return;
    }

    new_head = (*head)->next;
    free(*head);

    *head = new_head;
}

void gll_pop_end(struct gll_node *head) {
    struct gll_node *current = head;

    if (head->next == NULL) {
        free(head);
        return;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void gll_print(struct gll_node *head, void (*pfnct)(void*)) {
    while (head != NULL) {
        (*pfnct)(head->data);
        head = head->next;
    }
}

void gll_print_int(void *data) {
    printf("%d ", *(int*)data);
}
