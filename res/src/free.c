#include "ud_list.h"

void    ud_list_free(ud_list *begin)
{
    while (begin)
    {
        ud_ut_free(begin->data);
        ud_list *tmp = begin;
        begin = begin->next;
        ud_ut_free(tmp);
    }
}