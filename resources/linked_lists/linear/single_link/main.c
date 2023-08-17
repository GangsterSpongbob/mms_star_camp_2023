#include "single_link.h"

int main(void)
{
    int foo = 7;
    char boo = 'l';
    char moo[] = "moo";

    data d1 = create_data(&foo, INT);
    data d2 = create_data(&boo, CHAR);
    data d3 = create_data(moo, STRING);

    linked_list ll1 = init_list();

    push_back(&d1, &ll1);
    print_linked_list(&ll1);

    push_back(&d2, &ll1);
    print_linked_list(&ll1);

    push_front(&d3, &ll1);
    print_linked_list(&ll1);

    deinit_list(&ll1);
    print_linked_list(&ll1);

    return 0;
}