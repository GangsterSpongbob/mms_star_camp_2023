#include <stdio.h>

#include "utils.h"

double calculate_average_of_3_doubles(double num1, double num2, double num3)
{
    return (num1 + num2 + num3) / 3;
}
void print_average_of_3_doubles(double num1, double num2, double num3)
{
    printf("%s%lf%c%lf%c%lf%s%lf\n", "The average of the numbers ", num1, ',', num2, ',', num3, " is ", calculate_average_of_3_doubles(num1, num2, num3));
}