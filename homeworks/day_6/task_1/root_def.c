#include "root.h"

#include <stdint.h>

double root_approx(uint8_t base, double number)
{
    const float precision = 0.001;

    if (number < 1)
    {
        double iter = precision;

        while (abs_diff(number, pow_double(iter, base)) > precision && iter < 1)
        {
            iter += precision;
        }

        return iter;
    }
    else
    {
        double iter = 1 + precision;

        while (abs_diff(number, pow_double(iter, base)) > precision && iter < number / 2)
        {
            iter += precision;
        }

        return iter;
    }
}

double pow_double(double base, uint8_t exponent)
{
    double output = 1.0;

    for (uint8_t i = 0; i < exponent; i++)
    {
        output *= base;
    }

    return output;
}

double abs_diff(double lhs, double rhs)
{
    return (lhs - rhs) > 0 ? lhs - rhs : rhs - lhs;
}