#include <stdio.h>

#include "utils.h"

int main(void)
{
    int arr[] = {1, 2, -1, 3, 5, 11, 12, 13, 2, 100, 22};

    int *max = find_max(arr, sizeof(arr) / sizeof(int), sizeof(int), cmp_int);
    printf("%d\n", *max); // 100

    return 0;
}