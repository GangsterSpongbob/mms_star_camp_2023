#include <stdio.h>

#include "subseq.h"

int main(void)
{
    int initial_arr_len = 10;
    int arr[10] = {5, 4, 3, 2, 1, 10, 11, 2, 3, 4};

    int final_arr_len;
    int dest[initial_arr_len];

    subseq(arr, initial_arr_len, dest, &final_arr_len);

    printf("Size is: %d\n", final_arr_len);
    for (int i = 0; i < final_arr_len; i++)
    {
        printf("%d, ", dest[i]);
    }
}