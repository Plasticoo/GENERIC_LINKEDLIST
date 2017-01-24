#include "g_ll.h"

#include <stdio.h>

struct test {
    int a;
    int b;
};

void print_struct(void *data) {
    struct test *c = (struct test*)data;
    printf("Struct: %d %d\n", c->a, c->b);
}

int main(int argc, char *argv[])
{
    struct gll_node *list = NULL;
    struct gll_node *list_t = NULL;

    int i;
    int ordered[] = {1,2,3,4,5};

    struct test _ordered[] = {{1,2},{3,4},{5,6}};

    for (i = 0; i < 5; i++) {
        gll_push_top(&list, &ordered[i], sizeof(int));
        gll_push_end(list, &ordered[i], sizeof(int));
    }

    printf("Additions to the list: \n");
    gll_print(list, gll_print_int);
    printf("Size: %d\n", gll_length(list));

    gll_pop_top(&list);
    gll_pop_end(list);

    printf("Deletions from the list: \n");
    gll_print(list, gll_print_int);
    printf("Size: %d\n", gll_length(list));

    gll_pop_idx(&list, 2);

    printf("Deleting 3rd element: \n");
    gll_print(list, gll_print_int);
    printf("Size: %d\n", gll_length(list));

    printf("Printing in bytes: \n");
    gll_print(list, gll_print_byte);

    gll_free(list);

    printf("\nWorking with complex data now...\n");

    for (i = 0; i < 3; i++) {
        gll_push_top(&list_t, &_ordered[i], sizeof(struct test));
        gll_push_end(list_t, &_ordered[i], sizeof(struct test));
    }

    printf("Size: %d\n", gll_length(list_t));

    gll_print(list_t, print_struct);

    gll_free(list_t);

    return 0;
}
