#include <ud_list.h>

int main(void)
{
    ud_list *list = ud_list_init("allo");
    ud_list_add(list, "bjr");
    ud_list_add_last(list->next, "Slt");
    ud_list_print(list, char *, "%s");
}