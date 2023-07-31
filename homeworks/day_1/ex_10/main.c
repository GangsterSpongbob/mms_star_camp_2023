#include "utils.h"

#include <stdio.h>

int main(void)
{
    double num1, num2, num3;

    printf("Enter first number:");
    scanf("%lf", &num1);

    printf("Enter second number:");
    scanf("%lf", &num2);

    printf("Enter third number:");
    scanf("%lf", &num3);

    print_average_of_3_doubles(num1, num2, num3);

    return 0;
}