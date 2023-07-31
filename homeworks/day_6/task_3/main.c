#include <stdio.h>
#include <math.h>

#include "f_a_m.h"

int is_pos(int a)
{
    return a > 0;
}

int add_one(int a)
{
    return ++a;
}

int is_even(int a)
{
    return !(a % 2);
}

int map_to_self(int a)
{
    return a;
}

int is_prime(int a)
{
    if (is_even(a))
        return 0;

    for (size_t i = 2; i < sqrt((double)a); i += 2)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int get_square(int a)
{
    return a * a;
}

int get_one_bits(int a)
{
    int bit_count = 0;

    for (size_t i = 0; i < 64; i++)
    {
        bit_count += !!(a % 1ULL << i);
    }

    return bit_count;
}

int main(void)
{
    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    int dest[10];
    size_t new_size;
    filter_and_map(arr, 8, is_pos, add_one, dest, &new_size);

    printf("%s%ld\n", "New size is ", new_size);
    for (size_t i = 0; i < new_size; i++)
    {
        printf("%d ", dest[i]);
    }
    printf("\n");

    filter_and_map(arr, 8, is_even, map_to_self, dest, &new_size);

    printf("%s%ld\n", "New size is ", new_size);
    for (size_t i = 0; i < new_size; i++)
    {
        printf("%d ", dest[i]);
    }
    printf("\n");

    filter_and_map(arr, 8, is_prime, get_square, dest, &new_size);

    printf("%s%ld\n", "New size is ", new_size);
    for (size_t i = 0; i < new_size; i++)
    {
        printf("%d ", dest[i]);
    }
    printf("\n");

    filter_and_map(arr, 8, is_pos, get_one_bits, dest, &new_size);

    printf("%s%ld\n", "New size is ", new_size);
    for (size_t i = 0; i < new_size; i++)
    {
        printf("%d ", dest[i]);
    }
    printf("\n");
}