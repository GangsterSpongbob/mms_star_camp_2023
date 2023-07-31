#include "bit_funcs.h"

unsigned int ones_count(__uint64_t mask1, __uint32_t mask2, __uint16_t mask3, __uint8_t mask4)
{
    return mask1 & mask2 & mask3 & mask4;
}

void flip_odd_bits(__uint64_t *mask)
{
    __uint64_t current_mask = 1;

    for (__uint8_t i = 0; i < 64; i++)
    {
        if (i % 2 != 0) // check for odd index
        {
            if ((*mask & current_mask) != 0) //  if the bit is 1
            {
                *mask = *mask & ~current_mask;
            }
            else if ((*mask & current_mask) == 0) // if the bit is 0
            {
                // printf("%ld\n", *mask | current_mask);
                *mask = *mask | current_mask;
            }
        }

        current_mask = current_mask << 1;
    }
}

void mirror_bits(__uint16_t *mask)
{
    __uint16_t result = 0;
    __uint16_t current_mask = 1;

    for (int i = 0; i < 16; i++)
    {
        if ((*mask & (1 << (15 - i))) != 0)
        {
            result = result | current_mask;
        }

        current_mask = current_mask << 1;
    }

    *mask = result;
}

void flip_alternative(__uint64_t *mask)
{
    for (int i = 0; i < 64; i++)
    {
        int temp = *mask & 1ULL << 63;
        if (i % 2 == 0)
        {
            if (temp == 0)
            {
                *mask = (*mask << 1) | 1;
            }
            else
            {
                *mask = *mask << 1;
            }
        }
        else
        {
            if (temp == 0)
            {
                *mask = *mask << 1;
            }
            else
            {
                *mask = (*mask << 1) | 1;
            }
        }
    }
}