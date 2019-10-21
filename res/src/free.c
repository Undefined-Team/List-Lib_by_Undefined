#include "ud_list.h"

void    ud_list_free(void *list)
{
    void (*fp_free)(void *val) = ((ud_list *)list)->fp_free;
    ud_list *curr = list;
    ud_list *tmp;
    while (curr)
    {
        tmp = curr;
        curr = curr->next;
        if (fp_free) fp_free(tmp);
        else ud_ut_free(tmp);
    }
    list = NULL;
}