#include "bit_funcs.h"

int clear_bits(uint32_t *mask_arr, size_t n_items, size_t bit_index)
{
    for (size_t i = 0; i < n_items; i++)
    {
        mask_arr[i] = mask_arr[i] & ~(1LL << bit_index);
    }

    return 0;
}

int set_bits(uint32_t *mask_arr, size_t n_items, size_t bit_index)
{
    for (size_t i = 0; i < n_items; i++)
    {
        mask_arr[i] = mask_arr[i] | (1LL << bit_index);
    }

    return 0;
}

int check_bits(uint32_t *mask_arr, size_t n_items, size_t bit_index)
{
    uint8_t current_bit = !!(mask_arr[0] & (1LL << bit_index));
    for (size_t i = 0; i < n_items; i++)
    {
        if (!!(mask_arr[0] & (1LL << bit_index)) != current_bit)
        {
            return -1;
        }
    }

    return current_bit;
}