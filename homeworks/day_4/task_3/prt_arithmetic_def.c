#include "ptr_arithmetic.h"

int add_to_address(const int *const ptr, int position)
{
    return *(ptr + position);
}