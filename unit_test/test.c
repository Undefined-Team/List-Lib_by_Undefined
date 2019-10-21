#include <ud_list.h>
#include <ud_string.h>
#include <ud_utils.h>

typedef struct uds_list_test {
    void (*fp_free)(void *val);
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

int main(void)
{
    ud_list_test *list = ud_list_init(ud_list_test, a = ud_str_dup("salut"));
    list->fp_free = ud_free_list_test;
    ud_list_test *list2 = ud_list_init(ud_list_test, fp_free = ud_free_list_test);
    ud_list_test *list3 = ud_list_init(ud_list_test, a = ud_str_dup("test"));
    list3->fp_free = ud_free_list_test;

    ud_list_push(ud_list_test, list, b = 2);
    ud_list_fpush(ud_list_test, list, ud_fill_list, ud_str_dup("this is fp"), 2);
    ud_list_push(ud_list_test, list, a = ud_str_dup("slt"));
    ud_list_push(ud_list_test, list, a = ud_str_dup("slt"));
    ud_list_push(ud_list_test, list2, a = ud_str_dup("test"));
    ud_list_push(ud_list_test, list2, b = 2);
    ud_list_push(ud_list_test, list3, a = ud_str_dup("test3"));

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
    ud_list_free(list);
    ud_list_free(list2);
    ud_list_free(list3);
}