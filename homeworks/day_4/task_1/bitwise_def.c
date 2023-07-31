#include "bitwise.h"

#include <stdint.h>
#include <stdio.h>

uint16_t set_bit(uint16_t number, uint8_t positiion)
{
    return number | (1 << (positiion - 1));
}

uint8_t check_bit(uint16_t number, uint8_t position)
{
    return number & (1 << (position - 1)) ? 1 : 0;
}

uint16_t clear_bit(uint16_t number, uint8_t position)
{
    return number & ~(1 << (position - 1));
}

void print_bits(uint16_t number)
{
    for (int i = 0; i < 16; i++)
    {
        printf("%d", check_bit(number, 16 - i));
    }
    printf("\n");
}