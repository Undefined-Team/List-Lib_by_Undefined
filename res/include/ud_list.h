#ifndef UD_LIST_H
# define UD_LIST_H

// Lib
#include <ud_utils.h>

// Macro
// # define ud_list_init(data)     ud_list_init((void *) data)

// Structures
typedef struct      uds_list {
    void            *data;
    struct uds_list *next;
}                   ud_list;

// Prototypes
ud_list     *ud_list_init(void *data);

#endif