#include "ud_list.h"

void        *ud_list_init_ctr(size_t len)
{
    void    *elem = NULL;

    UD_UT_PROT_MALLOC(elem = ud_ut_malloc(len));
    ud_mem_set(elem, 0, len);
    return elem;
}