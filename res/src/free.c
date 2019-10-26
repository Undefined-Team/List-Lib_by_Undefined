#include "ud_list.h"

void    ud_list_free_ctr(char *type_name, void *list)
{
    ud_list_type *type_info = ud_list_type_get(type_name);
    void (*fp_free)(void *val) = NULL;
    if (type_info) fp_free = type_info->fp_free;
    ud_list *curr = list;
    ud_list *tmp;
    while (curr)
    {
        tmp = curr;
        curr = curr->next;
        if (fp_free) fp_free(tmp);
        else ud_ut_free(tmp);
    }
    (void)type_name;
    list = NULL;
}