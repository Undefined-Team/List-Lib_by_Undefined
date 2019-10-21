#ifndef UD_LIST_H
# define UD_LIST_H

// Lib
#include <ud_utils.h>

// Macro
# define ud_list_print(list, ctype, format_str) ({ ud_list *_list = list; while (_list) { printf(format_str, (ctype)_list->data); printf("\n"); _list = _list->next; } })
/*
# define ud_list_print(format_str, ctype) \
    ({ \
        ud_list *_list;
        while (_list)
        {
            printf(format_str, (ctype)_list->data);
            _list = _list->next;
        }
    })

    // <<< If need to modify ud_list_print >>>
*/ 

// # define ud_list_init(data)     ud_list_init((void *) data)

// Structures
typedef struct      uds_list {
    void            *data;
    struct uds_list *next;
}                   ud_list;

// Prototypes
ud_list     *ud_list_init(void *data);
void        ud_list_free(ud_list *begin);
ud_list     *ud_list_add(ud_list *begin, void *data);
ud_list     *ud_list_add_last(ud_list *last, void *data);

#endif