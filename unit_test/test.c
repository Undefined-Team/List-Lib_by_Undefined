#include <ud_list.h>
#include <ud_string.h>
#include <ud_utils.h>

typedef struct uds_list_test {
    struct uds_list_test *next;
    char *a;
    size_t b;
} ud_list_test;

void    ud_free_list_test(void *val)
{
    ud_list_test *to_free = (ud_list_test *)val;
    ud_ut_free(to_free->a);
    ud_ut_free(to_free);
}

void    ud_fill_list(ud_list_test *list, char *a, size_t b)
{
    list->a = a;
    list->b = b;
}

ud_list_type *ud_list_type_test(void)
{
    static ud_list_type *ud_list_type_test = NULL;
    if (!ud_list_type_test) ud_list_type_test = ud_list_type_search(ud_list_type_test);
    return ud_list_type_test;
}

int main(void)
{
    ud_list_test *list4 = ud_list_tinit(ud_list_test, &ud_free_list_test, NULL);
    ud_list_test *list = ud_list_init(ud_list_test, a = ud_str_dup("salut"));
    ud_list_test *list2 = ud_list_finit(ud_list_test, ud_fill_list, ud_str_dup("test ud fill fp"), 4);
    ud_list_test *list3 = ud_list_init(ud_list_test, a = ud_str_dup("test"));

    ud_list_push(list, b = 2);
    ud_list_fpush(list, ud_fill_list, ud_str_dup("this is fp"), 2);
    ud_list_push(list, a = ud_str_dup("slt"));
    ud_list_push(list, a = ud_str_dup("slt"));
    ud_list_push(list2, a = ud_str_dup("test"));
    ud_list_push(list2, b = 2);
    ud_list_push(list3, a = ud_str_dup("test3"));

    ud_list_test *list_tmp = list;
    while (list_tmp) {
        printf("%s%s %zd\n", UD_UT_COLOR_1, list_tmp->a, list_tmp->b);
        list_tmp = list_tmp->next;
    }
    ud_list_test *list2_tmp = list2;
    while (list2_tmp) {
        printf("%s%s %zd\n", UD_UT_COLOR_2, list2_tmp->a, list2_tmp->b);
        list2_tmp = list2_tmp->next;
    }
    ud_list_test *list3_tmp = list3;
    while (list3_tmp) {
        printf("%s%s %zd\n", UD_UT_COLOR_3, list3_tmp->a, list3_tmp->b);
        list3_tmp = list3_tmp->next;
    }
    ud_list_free(ud_list_test, list);
    ud_list_free(ud_list_test, list2);
    ud_list_free(ud_list_test, list3);
    ud_list_free(ud_list_test, list4);
    // ud_list_type_print();
}