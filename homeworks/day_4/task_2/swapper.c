#include "swapper.h"

void swap_pointers(int *const lhs, int *const rhs)
{
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}