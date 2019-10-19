#include "ud_list.h"

ud_list     *ud_list_init(void *data)
{
    ud_list *elem;

    UD_UT_PROT_MALLOC(elem = ud_ut_malloc(sizeof(ud_list)));
    elem->data = data;
    elem->next = NULL;
    return elem;
}