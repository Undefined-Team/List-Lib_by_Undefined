#include "ud_list.h"

ud_list     *ud_list_add(ud_list *begin, void *data)
{
    if (!begin) return NULL;
    ud_list *elem = ud_list_init(data);
    while (begin->next)
        begin = begin->next;
    begin->next = elem;
    return elem;
}