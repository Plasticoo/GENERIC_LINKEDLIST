#include "g_ll.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    struct gll_node *list = NULL;

    int i;
    int ordered[] = {1,2,3,4,5};

    for (i = 0; i < 5; i++) {
        //gll_push_top(&list, &ordered[i], sizeof(int));
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

    gll_free(list);

    return 0;
}
