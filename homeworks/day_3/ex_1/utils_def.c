#include "utils.h"

#include <stdio.h>

void print_number_info(int number, int lower_bound, int upper_bound)
{
    if (number > upper_bound)
        printf("%s%d%s%d\n", "Number ", number, " is greater than ", upper_bound);
    else if (number > lower_bound)
        printf("%s%d%s%d%s%d\n", "Number ", number, " is greater than ", lower_bound, " but less than or equal to ", upper_bound);
    else
        printf("%s%d%s%d\n", "Number ", number, " is less than ", lower_bound);
}