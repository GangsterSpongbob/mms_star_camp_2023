#include "bitwise_double.h"

#include <stdio.h>
#include <stdint.h>

void print_bits_of_double(double mask)
{
    uint64_t binary_representation = *(uint64_t *)&mask;

    for (size_t i = 0; i < 64; i++)
    {
        printf("%d", !!(binary_representation & (1ULL << (63 - i))));
    }

    printf("\n");
}

void print_separated_double_bits(double mask)
{
    uint64_t binary_representation = *(uint64_t *)&mask;

    for (size_t i = 0; i < 64; i++)
    {
        printf("%d", !!(binary_representation & (1ULL << (63 - i))));
        if (i == 0 || i == 11)
        {
            printf(" ");
        }
    }

    printf("\n");
}