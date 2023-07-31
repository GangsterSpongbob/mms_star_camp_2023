#include "utils.h"

#include <stdio.h>

int calculate_integer_sum(int lhs, int rhs)
{
    return lhs + rhs;
}

void print_integer_sum(int lhs, int rhs)
{
    printf("%s%d%s%d%s%d\n", "The sum of numbers ", lhs, " and ", rhs, " is ", calculate_integer_sum(lhs, rhs));
}