#include <stdio.h>
#include <stdint.h>

#include "bitwise_double.h"

int main(void)
{
    print_bits_of_double(162.42);
    print_separated_double_bits(162.42);

    return 0;
}