#include <stdio.h>

#include "math_funcs.h"

int main(void)
{
    printf("%d\n", add_integers(2, 7));
    printf("%d\n", multiply_integers(2, 7));

    int number = 5;
    square_int_pointer(&number);

    printf("%d\n", factorial(7));
    printf("%d\n", fibonacci(7));

    return 0;
}