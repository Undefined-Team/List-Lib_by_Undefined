#include <ud_list.h>

int main(void)
{
    ud_list *list = ud_list_init("allo");
    printf("%s\n", list->data);
}