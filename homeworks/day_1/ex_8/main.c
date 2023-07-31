#include <stdio.h>

#include "utils.h"

int main(void)
{
    int lhs, rhs;

    printf("Enter first number: ");
    scanf("%d", &lhs);

    printf("Enter second number: ");
    scanf("%d", &rhs);

    print_integer_sum(lhs, rhs);

    return 0;
}