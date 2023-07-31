#include <stdio.h>

#include "utils.h"

int main(void)
{
    double fahrenheit, celsius;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);

    // printf("Enter temperature in Celsius: ");
    // scanf("%lf", &celsius);

    // print_c_to_f(celsius);

    print_f_to_c(fahrenheit);

    return 0;
}