#include <stdio.h>

#include "stack.h"

int main(void)
{
    int foo = 7;
    char boo = 'l';
    char moo[] = "moo";
    double goo = 13.37;

    data d1 = create_data(&foo, INT);
    data d2 = create_data(&boo, CHAR);
    data d3 = create_data(moo, STRING);
    data d4 = create_data(&goo, DOUBLE);

    linked_list ll1 = init_list();

    push_back(&d1, &ll1);
    print_linked_list(&ll1);

    push_back(&d2, &ll1);
    print_linked_list(&ll1);

    char second = *(char *)(pop_back(&ll1)->value);
    printf("%s%c\n", "Popped ", second);
    print_linked_list(&ll1);

    push_back(&d3, &ll1);
    print_linked_list(&ll1);

    push_back(&d4, &ll1);
    print_linked_list(&ll1);

    push_back(&d1, &ll1);
    print_linked_list(&ll1);

    deinit_list(&ll1);
    print_linked_list(&ll1);

    return 0;
}