#include <stdio.h>

#include "math_utils.h"

int main(void)
{
    double sample_number = 11;
    printf("%s%.2f%s%.2f\n", "The square of ", sample_number, " is ", square(sample_number));
    printf("%s%.2f%s%.2f\n", "The cube of ", sample_number, " is ", cube(sample_number));

    return 0;
}