#include "subseq.h"

void subseq(int arr[], int n, int dest[], int *new_n)
{
    int index = 0;
    int max_counter = 0;

    while (index < n)
    {
        int current_index = 0;
        int dest_counter = 0;
        int current_sub_array[n];

        do
        {
            current_sub_array[current_index] = arr[index + current_index];
            dest_counter++;
            current_index++;
        } while (index + current_index < n && arr[index + current_index] < arr[index + current_index - 1]);

        if (dest_counter > max_counter)
        {
            max_counter = dest_counter;

            for (int i = 0; i < dest_counter; i++)
            {
                dest[i] = current_sub_array[i];
            }
        }

        index += current_index;
    }

    *new_n = max_counter;
}