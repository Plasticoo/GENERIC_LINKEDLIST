#ifndef _G_LL_H_
#define _G_LL_H_

#include <stdlib.h>

struct gll_node {
    void *data;
    struct gll_node *next;
};


void gll_push_top(struct gll_node **head, void *data, size_t data_size);
void gll_push_end(struct gll_node *head, void *data, size_t data_size);

void gll_pop_top(struct gll_node **head);
void gll_pop_end(struct gll_node *head);

void gll_print(struct gll_node *head, void (*pfnct)(void*));
void gll_print_int(void *data);

#endif
