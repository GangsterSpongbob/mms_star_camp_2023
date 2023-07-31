#include "bitwise.h"

int main(void)
{
    int foo = 63;
    print_bits(foo);
    foo = clear_bit(foo, 3);
    foo = set_bit(foo, 14);
    print_bits(foo);

    return 0;
}