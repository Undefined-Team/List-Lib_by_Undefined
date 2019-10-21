#include "ud_list.h"

ud_list     *ud_list_add_last(ud_list *last, void *data)
{
    if (!last) return NULL;
    ud_list *elem = ud_list_init(data);
    last->next = elem;
    return elem;
}