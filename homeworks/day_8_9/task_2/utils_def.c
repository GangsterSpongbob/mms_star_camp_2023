#include "utils.h"

void *find_max(void *arr, size_t elem_count, size_t elem_size, int (*cmp)(const void *, const void *))
{
    void *max_el = arr;
    for (size_t i = 0; i < elem_count; i++)
    {
        if (cmp((char *)arr + i * elem_size, max_el) > 1)
        {
            max_el = (char *)arr + i * elem_size;
        }
    }

    return max_el;
}

int cmp_int(const void *lhs, const void *rhs)
{
    return *(int *)lhs - *(int *)rhs;
}