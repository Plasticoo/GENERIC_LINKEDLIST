#include "g_ll.h"

int main(int argc, char *argv[])
{
    struct gll_node *list = NULL;

    int i;
    int ordered[] = {1,2,3,4,5};

    for (i = 0; i < 5; i++) {
        gll_push_top(&list, &ordered[i], sizeof(int));
        gll_push_end(list, &ordered[i], sizeof(int));
    }

    gll_print(list, gll_print_int);

    return 0;
}
