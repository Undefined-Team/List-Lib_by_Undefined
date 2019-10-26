#include <ud_list.h>
#include <ud_string.h>
#include <ud_utils.h>

ud_list_struct(ud_list_test, char *a; size_t b);
ud_list_define(ud_list_test, ud_free_list_test, NULL);
ud_list_struct(ud_list_test2, char *a; size_t b);
ud_list_define(ud_list_test2, ud_free_list_test, NULL);
ud_list_struct(ud_list_test3, char *a; size_t b);
ud_list_define(ud_list_test3, ud_free_list_test, NULL);
ud_list_struct(ud_list_test4, char *a; size_t b);
ud_list_define(ud_list_test4, ud_free_list_test, NULL);
ud_list_struct(ud_list_test5, char *a; size_t b);
ud_list_define(ud_list_test5, ud_free_list_test, NULL);
ud_list_struct(ud_list_test6, char *a; size_t b);
ud_list_define(ud_list_test6, ud_free_list_test, NULL);
ud_list_struct(ud_list_test7, char *a; size_t b);
ud_list_define(ud_list_test7, ud_free_list_test, NULL);
ud_list_struct(ud_list_test8, char *a; size_t b);
ud_list_define(ud_list_test8, ud_free_list_test, NULL);
ud_list_struct(ud_list_test9, char *a; size_t b);
ud_list_define(ud_list_test9, ud_free_list_test, NULL);

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
    printf("tinit list4\n");
    ud_list_test *list4 = ud_list_tinit(UD_LIST(ud_list_test), ud_list_test, a = ud_str_dup("cc"));
    printf("init list\n");
    ud_list_test *list = ud_list_init(ud_list_test, a = ud_str_dup("salut"));
    printf("finit list2\n");
    ud_list_test *list2 = ud_list_finit(ud_list_test, ud_fill_list, ud_str_dup("test ud fill fp"), 4);
    printf("init list3\n");
    ud_list_test *list3 = ud_list_init(ud_list_test, a = ud_str_dup("test"));
    ud_list_test *list5 = ud_list_tinit(UD_LIST(ud_list_test2), ud_list_test, a = ud_str_dup("cc"));
    ud_list_test *list6 = ud_list_tinit(UD_LIST(ud_list_test3), ud_list_test, a = ud_str_dup("cc"));

    printf("push list\n");
    ud_list_push(list, b = 2);
    printf("fpush list\n");
    ud_list_fpush(list, ud_fill_list, ud_str_dup("this is fp"), 2);
    printf("push list\n");
    ud_list_push(list, a = ud_str_dup("slt"));
    printf("push list\n");
    ud_list_push(list, a = ud_str_dup("slt"));
    printf("push list2\n");
    ud_list_push(list2, a = ud_str_dup("test"));
    printf("push list2\n");
    ud_list_push(list2, b = 2);
    printf("push list3\n");
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
    ud_list_free(ud_list_test2, list5);
    ud_list_free(ud_list_test3, list6);
    ud_list_type_print();
}