#include "ud_list.h"

void __attribute__ ((destructor))  ud_list_type_dtor() { ud_list_type_free(); }

ud_list_type *ud_list_type_new(ud_list_type *found, void (*fp_free)(void *), void (*fp_print)(void *), char *type_name)
{
    ud_list_type *list = NULL;

    if (!found)
    {
        ud_ut_prot_malloc(list = ud_ut_malloc(sizeof(ud_list_type)));
        list->fp_free = fp_free;
        list->fp_print = fp_print;
        list->next = NULL;
        list->type_name = type_name;
    }
    return list;
}

void            ud_list_type_default_free(void *val)
{
    ud_list *list = (ud_list *)val;
    ud_ut_free(list);
}

ud_list_type    *ud_list_type_add(ud_list_type **p_list, void *v_new_elem)
{
    if (!v_new_elem) return *p_list;
    ud_list_type *list = *p_list;
    static ud_list_type *end = NULL;

    if (!list)
    {
        list = ud_list_type_new(NULL, &ud_list_type_default_free, NULL, "ud_list");
        end = list;
    }
    ud_list_type *new_elem = (ud_list_type *)v_new_elem;
    end->next = new_elem;
    end = end->next;
    *p_list = list;
    return list;
}

ud_list_type    *ud_list_type_search_ctr(ud_list_type **p_list, void *p_type_name)
{
    if (!p_list || !p_type_name) return NULL;
    ud_list_type *list = *p_list;
    char *type_name = (char *)p_type_name;
    ud_list_type *curr = list;
    
    for (; curr; curr = curr->next)
        if (!ud_str_cmp(type_name, curr->type_name)) return curr;
    return NULL;
}

ud_list_type    *ud_list_type_free_ctr(ud_list_type **p_list, void *p_type_name)
{
    ud_list_type *list = *p_list;
    ud_list_type *curr;

    while (list)
    {
        curr = list;
        printf("%s\n", list->type_name);
        list = list->next;
        ud_ut_free(curr);
    }
    (void)p_type_name;
    return NULL;
}

ud_list_type    *ud_list_type_print_ctr(ud_list_type **p_list, void *tmp)
{
    ud_list_type *list = *p_list;
    ud_list_type *curr = list;
    size_t i = 0;
    while (curr)
    {
        printf("[%zu]: %s, %p\n", i++, curr->type_name, curr->fp_free);
        curr = curr->next;
    }
    (void)tmp;
    return list;
}

ud_list_type    *ud_list_type_ctr(ud_list_type *(*fp_action)(ud_list_type **, void *), void *info)
{
    static ud_list_type *list = NULL;

    return fp_action(&list, info);
}