#ifndef UD_LIST_H
# define UD_LIST_H

// Lib
#include <ud_utils.h>
#include <ud_memory.h>

// Macro
# define ud_list_print(list, ctype, format_str) ({ ud_list *_list = list; while (_list) { printf(format_str, (ctype)_list->data); printf("\n"); _list = _list->next; } })
/*
# define ud_list_print(format_str, ctype) \
    ({ \
        ud_list *_list = list;
        while (_list)
        {
            printf(format_str, (ctype)_list->data);
            _list = _list->next;
        }
    })

    // <<< If need to modify ud_list_print >>>
*/

# define ud_list_init(ctype, declaration) \
    ({ \
        ctype *_list; \
        size_t len = sizeof(ctype); \
        _list = ud_list_init_ctr(len); \
        _list->next = NULL; \
        _list->fp_free = NULL; \
        _list->declaration; \
        _list; \
    })

# define ud_list_finit(ctype, fp, ...) \
    ({ \
        ctype *_list; \
        size_t len = sizeof(ctype); \
        _list = ud_list_init_ctr(len); \
        _list->next = NULL; \
        _list->fp_free = NULL; \
        fp(_list, __VA_ARGS__); \
        _list; \
    })

# define ud_list_push_ctr(last, ctype, _list, declaration) \
    ({ \
        ctype *_curr = _list; \
        if (!last) \
            while (_curr->next) \
                _curr = _curr->next; \
        _curr->next = ud_list_init_ctr(sizeof(*_list)); \
        _curr->next->next = NULL; \
        _curr->next->fp_free = NULL; \
        _curr->next->declaration; \
        _curr->next; \
    })

# define ud_list_fpush_ctr(last, ctype, _list, fp, ...) \
    ({ \
        ctype *_curr = _list; \
        if (!last) \
            while (_curr->next) \
                _curr = _curr->next; \
        _curr->next = ud_list_init_ctr(sizeof(*_list)); \
        _curr->next->next = NULL; \
        _curr->next->fp_free = NULL; \
        fp(_curr->next, __VA_ARGS__); \
        _curr->next; \
    })

# define ud_list_free(ctype, _list) \
    ({ \
        void (*fp_free)(void *val) = _list->fp_free; \
        ctype *_curr = _list; \
        ctype *_tmp; \
        while (_curr) \
        { \
            _tmp = _curr; \
            _curr = _curr->next; \
            if (fp_free) fp_free(_tmp); \
            else ud_ut_free(_tmp); \
        } \
        _list = NULL; \
        _list; \
    })

# define ud_list_push(ctype, _list, declaration)        ud_list_push_ctr(0, ctype, _list, declaration)
# define ud_list_push_last(ctype, _list, declaration)   ud_list_push_ctr(1, ctype, _list, declaration)
# define ud_list_fpush(ctype, _list, fp, ...)           ud_list_fpush_ctr(0, ctype, _list, fp, __VA_ARGS__)
# define ud_list_fpush_last(ctype, _list, fp, ...)      ud_list_fpush_ctr(1, ctype, _list, fp, __VA_ARGS__)

// macros for using ud_lst instead of ud_list
# define ud_lst_init(ctype, declaration)                ud_list_init(ctype, declaration)
# define ud_lst_finit(ctype, fp, ...)                   ud_list_init(ctype, fp, __VA_ARGS__)
# define ud_lst_push(ctype, _list, declaration)         ud_list_push_ctr(0, ctype, _list, declaration)
# define ud_lst_push_last(ctype, _list, declaration)    ud_list_push_ctr(1, ctype, _list, declaration)
# define ud_lst_fpush(ctype, _list, fp, ...)            ud_list_fpush_ctr(0, ctype, _list, fp, __VA_ARGS__)
# define ud_lst_fpush_last(ctype, _list, fp, ...)       ud_list_fpush_ctr(1, ctype, _list, fp, __VA_ARGS__)
# define ud_lst_free(ctype, _list)                      ud_list_free(ctype, _list)


// Structures
typedef struct      uds_list {
    void            (*fp_free)(void *val);
    struct uds_list *next;
    void            *data;
}                   ud_list;

// Prototypes
void        *ud_list_init_ctr(size_t len);

#endif