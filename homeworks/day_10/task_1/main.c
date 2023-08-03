#include <stdio.h>
#include <stdint.h>

void swap_bytes(uint16_t *);

int main(void)
{
    uint16_t foo = 0b0010101101100101;
    swap_bytes(&foo);
    printf("%d\n", foo);
}

void swap_bytes(uint16_t *word)
{
    for (size_t i = 0; i < 8; i++)
    {
        uint16_t current_bit = *word & 1;
        *word = *word >> 1;
        *word = *word | current_bit << 15;
    }
}