#ifndef UD_LIST_H
# define UD_LIST_H

// Lib
#include <ud_utils.h>
#include <ud_memory.h>
#include <ud_string.h>

// Macro
# define ud_list_type_init(ctype, fp_free, fp_print)    ud_list_type_ctr(&ud_list_type_add, ud_list_type_new(ud_list_type_ctr(&ud_list_type_search_ctr, #ctype), fp_free, fp_print, #ctype))
# define ud_list_type_search(ctype)                     ud_list_type_ctr(&ud_list_type_search_ctr, ctype)
# define ud_list_type_print()                           ud_list_type_ctr(&ud_list_type_print_ctr, NULL)
# define ud_list_type_free()                            (void)ud_list_type_ctr(&ud_list_type_free_ctr, NULL);

# define ud_list_minit(ctype) \
    ({ \
        ctype *_list; \
        size_t len = sizeof(ctype); \
        _list = ud_list_init_ctr(len); \
        ud_list_type_init(ctype, NULL, NULL); \
        _list; \
    })

# define ud_list_tinit(ctype, fp_free, fp_print) \
    ({ \
        ctype *_list; \
        size_t len = sizeof(ctype); \
        _list = ud_list_init_ctr(len); \
        ud_list_type_init(ctype, fp_free, fp_print); \
        _list; \
    })

# define ud_list_init(ctype, declaration) \
    ({ \
        ctype *_list; \
        size_t len = sizeof(ctype); \
        _list = ud_list_init_ctr(len); \
        _list->declaration; \
        ud_list_type_init(ctype, NULL, NULL); \
        _list; \
    })

# define ud_list_finit(ctype, fp, ...) \
    ({ \
        ctype *_list; \
        size_t len = sizeof(ctype); \
        _list = ud_list_init_ctr(len); \
        fp(_list, __VA_ARGS__); \
        ud_list_type_init(ctype, NULL, NULL); \
        _list; \
    })

# define ud_list_mpush_ctr(_list) \
    ({ \
        typeof(_list) _curr = _list; \
        while (_curr->next) \
            _curr = _curr->next; \
        _curr->next = ud_list_init_ctr(sizeof(*_list)); \
        _curr->next; \
    })

# define ud_list_push_ctr(_list, declaration) \
    ({ \
        typeof(_list) _curr = _list; \
        while (_curr->next) \
            _curr = _curr->next; \
        _curr->next = ud_list_init_ctr(sizeof(*_list)); \
        _curr->next->declaration; \
        _curr->next; \
    })

# define ud_list_fpush_ctr(_list, fp, ...) \
    ({ \
        typeof(_list) _curr = _list; \
        while (_curr->next) \
            _curr = _curr->next; \
        _curr->next = ud_list_init_ctr(sizeof(*_list)); \
        fp(_curr->next, __VA_ARGS__); \
        _curr->next; \
    })

# define ud_list_push(_list, declaration)               ud_list_push_ctr(_list, declaration)
# define ud_list_mpush(_list)                           ud_list_mpush_ctr(_list)
# define ud_list_fpush(_list, fp, ...)                  ud_list_fpush_ctr(_list, fp, __VA_ARGS__)

# define ud_list_free(ctype, _list)                     ud_list_free_ctr(#ctype, _list)

// macros for using ud_lst instead of ud_list
# define ud_lst_init(ctype, declaration)                ud_list_init(ctype, declaration)
# define ud_lst_finit(ctype, fp, ...)                   ud_list_init(ctype, fp, __VA_ARGS__)
# define ud_lst_minit(ctype)                            ud_list_minit(ctype)
# define ud_lst_push(_list, declaration)                ud_list_push_ctr(_list, declaration)
# define ud_lst_mpush(_list)                            ud_list_mpush_ctr(_list)
# define ud_lst_fpush(_list, fp, ...)                   ud_list_fpush_ctr(_list, fp, __VA_ARGS__)
# define ud_lst_free(ctype, _list)                      ud_list_free(ctype, _list)

// Structures
typedef enum                {ud_list_req_add, ud_list_req_search, ud_list_req_free} ud_list_type_req; 

typedef struct              uds_list {
    struct uds_list         *next;
    void                    *data;
}                           ud_list;

typedef struct              uds_list_type {
    void                    (*fp_free)(void *val);
    void                    (*fp_print)(void *val);
    struct uds_list_type    *next;
    char                    *type_name;
}                           ud_list_type;

// Prototypes
void                    *ud_list_init_ctr(size_t len);
void                    ud_list_free_ctr(char *type_name, void *list);
ud_list_type            *ud_list_type_ctr(ud_list_type *(*fp_action)(ud_list_type **, void *), void *info);
ud_list_type            *ud_list_type_free_ctr(ud_list_type **list, void *p_type_name);
ud_list_type            *ud_list_type_search_ctr(ud_list_type **list, void *p_type_name);
ud_list_type            *ud_list_type_add(ud_list_type **list, void *v_new_elem);
ud_list_type            *ud_list_type_print_ctr(ud_list_type **list, void *tmp);
void                    ud_list_type_default_free(void *val);
ud_list_type            *ud_list_type_new(ud_list_type *found, void (*fp_free)(void *), void (*fp_print)(void *), char *type_name);

#endif