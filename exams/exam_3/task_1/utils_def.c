#include "utils.h"

#include <stdio.h>

void print_char_to_bin(char cur_char)
{
    for (size_t i = 0; i < 8; i++)
    {
        printf("%d", !!(cur_char & 0b10000000));
        cur_char = cur_char << 1;
    }
    printf(" ");
}

void print_char_to_hex(uint8_t cur_char)
{
    printf("%d ", cur_char);
}