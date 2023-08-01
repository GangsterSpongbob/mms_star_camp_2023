#include "sums.h"

#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

uint8_t has_decimal_dot(char *check_for_dot)
{
    uint8_t index = 0;
    while (check_for_dot[index] != '\0')
    {
        if (check_for_dot[index++] == '.')
        {
            return 1;
        }
    }

    return 0;
}

double sum_of_cli_input(int argc, char *argv[])
{
    double sum = 0;

    for (size_t i = 0; i < argc; i++)
    {
        if (argv[i][0] == '0' && toupper(argv[i][1]) == 'X')
        {
            sum += (int)strtol(argv[i], NULL, 16);
        }
        else if (has_decimal_dot(argv[i]))
        {
            sum += strtod(argv[i], NULL);
        }
        else
        {
            sum += (int)strtol(argv[i], NULL, 10);
        }
    }

    return sum;
}
