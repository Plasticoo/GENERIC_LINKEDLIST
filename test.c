#include "g_ll.h"

int main(int argc, char *argv[])
{
    struct gll_node *list = NULL;
    int a = 1;

    gll_push_top(&list, &a, sizeof(int));
    gll_push_end(list, &a, sizeof(int));

    return 0;
}
