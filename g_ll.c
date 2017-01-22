#include "g_ll.h"

#include <stdlib.h>
#include <stdio.h>

void gll_push_top(struct gll_node **head, void *data, size_t data_size) {
    int i;
    struct gll_node *new_node = malloc(sizeof(struct gll_node));

    new_node->data = malloc(data_size);
    new_node->next = *head;

    for (i = 0; i < (int)data_size; i++) {
        *(char *)(new_node->data + i) = *(char *)(data + i);
    }

    *head = new_node;
}

void gll_push_end(struct gll_node *head, void *data, size_t data_size) {
    int i;
    struct gll_node *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct gll_node));
    current->next->data = malloc(data_size);
    current->next->next = NULL;

    for (i = 0; i < (int)data_size; i++) {
        *(char*)(current->next->data + i) = *(char*)(data + i);
    }
}

void gll_pop_top(struct gll_node **head) {
    struct gll_node *new_head = *head;

    if (new_head) {
        *head = new_head->next;

        free(new_head->data);
        free(new_head);
    }
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

    free(current->next->data);
    free(current->next);
    current->next = NULL;
}

void gll_pop_idx(struct gll_node **head, int index) {
    int i;
    struct gll_node *current = *head;
    struct gll_node *temp = NULL;

    if (index == 0) {
        gll_pop_top(head);
    }

    for (i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            return;
        }

        current = current->next;
    }

    temp = current->next;
    current->next = temp->next;

    free(temp->data);
    free(temp);
}

int gll_length(struct gll_node *head) {
    int count = 0;
    struct gll_node *current = head;

    while(current->next != NULL) {
        count++;
        current = current->next;
    }

    return count + 1;
}

void gll_free(struct gll_node *head) {
    struct gll_node *temp;

    while((temp = head)) {
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

void gll_print(struct gll_node *head, void (*pfnct)(void*)) {
    while (head != NULL) {
        (*pfnct)(head->data);
        head = head->next;
    }

    putchar('\n');
}

void gll_print_int(void *data) {
    printf("%d ", *(int*)data);
}

void gll_print_char(void *data) {
    printf("%c ", *(char*)data);
}

void gll_print_float(void *data) {
    printf("%f ", *(float*)data);
}

void gll_print_double(void *data) {
    printf("%lf ", *(double*)data);
}
