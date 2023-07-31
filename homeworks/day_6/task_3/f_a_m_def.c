#include "f_a_m.h"

void filter_and_map(
    const int arr[],
    size_t n,
    int (*filter_f)(int),
    int (*map_f)(int),
    int dest[],
    size_t *dest_cnt)
{
    *dest_cnt = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (filter_f(arr[i]))
        {
            dest[(*dest_cnt)++] = map_f(arr[i]);
        }
    }
}