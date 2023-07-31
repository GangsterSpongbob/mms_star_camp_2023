#include "math_funcs.h"

#include <stdio.h>

int add_integers(int lhs, int rhs)
{
    return lhs + rhs;
}

int multiply_integers(int lhs, int rhs)
{
    return lhs * rhs;
}

void square_int_pointer(int *input_number)
{
    *input_number *= *input_number;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;

    else if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}