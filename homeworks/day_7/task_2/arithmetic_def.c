#include "arithmetic.h"

double pow_int(int base, int exponent)
{
    double reslult = 1;

    for (int i = 0; i < exponent; i++)
    {
        reslult *= base;
    }

    return reslult;
}