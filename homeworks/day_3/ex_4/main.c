#include <stdio.h>

void reverse_array(int *arr, int length)
{
    int *start = arr;
    int *end = arr + length - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}

int main(void)
{
    int number_arr[5] = {1, 2, 3, 4, 5};
    int length = sizeof(number_arr) / sizeof(number_arr[0]);

    printf("Original array: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", number_arr[i]);
    }
    printf("\n");

    reverse_array(number_arr, length);

    printf("Reversed array: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", number_arr[i]);
    }
    printf("\n");

    return 1;
}