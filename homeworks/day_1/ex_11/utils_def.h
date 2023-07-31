#include "utils.h"

#include <stdio.h>

double convert_fahrenheit_to_celsius(double fahrhenheit)
{
    return (fahrhenheit - 32) * 5 / 9;
}

double convert_celsius_to_fahrenheit(double celsius)
{
    return celsius * 9 / 5 + 32;
}

void print_f_to_c(double fahrenheit)
{
    printf("%lf%s%lf%s\n", fahrenheit, " degrees Fahrhenheit are equivalent to ", convert_fahrenheit_to_celsius(fahrenheit), " degrees Celsius.");
}

void print_c_to_f(double celsius)
{
    printf("%lf%s%lf%s\n", celsius, " degrees Celsius are equivalent to ", convert_celsius_to_fahrenheit(celsius), " degrees Fahrenheit.");
}