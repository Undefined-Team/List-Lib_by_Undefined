#include <ud_list.h>

int main(void)
{
    ud_list *list = ud_list_init("allo");
    ud_list_add(list, "bjr");
    ud_list_add_last(list->next, "Slt");
    ud_list_print(list, char *, "%s ");
    ud_list *list2 = NULL;
    size_t i = 0;
    while (++i < 5)
        list2 = ud_list_init_or_push(list2, "salut");
    ud_list_print(list2, char *, "%s ");
}