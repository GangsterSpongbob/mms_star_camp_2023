#include <stdio.h>

#define ARR_LEN 10

int main(void)
{
    int arr[ARR_LEN] = {1, 2, 3, 0, 6, 4, 7, 1, 23, 16};
    int min_el = arr[0];
    int max_el = arr[0];
    double sum = 0;

    for (int i = 0; i < ARR_LEN; i++)
    {
        if (arr[i] < min_el)
            min_el = arr[i];
        if (arr[i] > max_el)
            max_el = arr[i];
        sum += arr[i];
    }

    printf("%s%d%s%d%s%f\n", "Min element is ", min_el, ", max element is", max_el, " and average is ", sum / ARR_LEN);

    return 0;
}