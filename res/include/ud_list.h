#ifndef UD_LIST_H
# define UD_LIST_H

// Lib
#include <ud_utils.h>
#include <ud_memory.h>

// Macro
# define ud_list_minit(ctype) \
    ({ \
        ctype *_list; \
        size_t len = sizeof(ctype); \
        _list = ud_list_init_ctr(len); \
        _list; \
    })

# define ud_list_init(ctype, declaration) \
    ({ \
        ctype *_list; \
        size_t len = sizeof(ctype); \
        _list = ud_list_init_ctr(len); \
        _list->declaration; \
        _list; \
    })

# define ud_list_finit(ctype, fp, ...) \
    ({ \
        ctype *_list; \
        size_t len = sizeof(ctype); \
        _list = ud_list_init_ctr(len); \
        fp(_list, __VA_ARGS__); \
        _list; \
    })

# define ud_list_mpush_ctr(ctype, _list) \
    ({ \
        ctype *_curr = _list; \
        while (_curr->next) \
            _curr = _curr->next; \
        _curr->next = ud_list_init_ctr(sizeof(*_list)); \
        _curr->next; \
    })

# define ud_list_push_ctr(ctype, _list, declaration) \
    ({ \
        ctype *_curr = _list; \
        while (_curr->next) \
            _curr = _curr->next; \
        _curr->next = ud_list_init_ctr(sizeof(*_list)); \
        _curr->next->declaration; \
        _curr->next; \
    })

# define ud_list_fpush_ctr(ctype, _list, fp, ...) \
    ({ \
        ctype *_curr = _list; \
        while (_curr->next) \
            _curr = _curr->next; \
        _curr->next = ud_list_init_ctr(sizeof(*_list)); \
        fp(_curr->next, __VA_ARGS__); \
        _curr->next; \
    })

# define ud_list_push(ctype, _list, declaration)        ud_list_push_ctr(ctype, _list, declaration)
# define ud_list_mpush(ctype, _list)                    ud_list_mpush_ctr(ctype, _list)
# define ud_list_fpush(ctype, _list, fp, ...)           ud_list_fpush_ctr(ctype, _list, fp, __VA_ARGS__)

// macros for using ud_lst instead of ud_list
# define ud_lst_init(ctype, declaration)                ud_list_init(ctype, declaration)
# define ud_lst_finit(ctype, fp, ...)                   ud_list_init(ctype, fp, __VA_ARGS__)
# define ud_lst_minit(ctype)                            ud_list_minit(ctype)
# define ud_lst_push(ctype, _list, declaration)         ud_list_push_ctr(ctype, _list, declaration)
# define ud_lst_mpush(ctype, _list)                     ud_list_mpush_ctr(ctype, _list)
# define ud_lst_fpush(ctype, _list, fp, ...)            ud_list_fpush_ctr(ctype, _list, fp, __VA_ARGS__)
# define ud_lst_free(ctype, _list)                      ud_list_free(_list)


// Structures
typedef struct      uds_list {
    void            (*fp_free)(void *val);
    struct uds_list *next;
    void            *data;
}                   ud_list;

// Prototypes
void        *ud_list_init_ctr(size_t len);
void        ud_list_free(void *list);

#endif