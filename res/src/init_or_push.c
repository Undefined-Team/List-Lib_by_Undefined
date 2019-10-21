#include "ud_list.h"

ud_list     *ud_list_init_or_push(ud_list *list, void *data)
{
    if (!list) return ud_list_init(data);
    ud_list_add(list, data);
    return list;
}