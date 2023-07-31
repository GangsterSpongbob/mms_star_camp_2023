#include <stdio.h>

#define PI 3.14159

double calculate_circumference(double);
void print_circumference(double);

int main(void)
{
    double radius = 5.0;
    print_circumference(radius);

    return 0;
}

double calculate_circumference(double radius)
{
    return 2 * PI * radius;
}

void print_circumference(double radius)
{
    printf("%s%lf%s%lf\n", "The circumference of a circle with radius ", radius, " is ", calculate_circumference(radius));
}