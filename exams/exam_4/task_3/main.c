#include <stdio.h>
#include <pthread.h>

int main(void)
{
    unsigned int m, n;
    scanf("%i %i", &m, &n);
    int *num_arrs[100];
    unsigned int num_arr_index = 0;
    for (size_t i = 0; i < n; i++)
    {
        char buffer[100];
        scanf("%s", buffer);
        if (buffer[0] != 'R' || buffer[1] != 'O' || buffer[2] != 'W' || buffer[3] != '\0')
        {
            continue;
        }
        int nums[100];
        for (size_t i = 0; i < m; i++)
        {
            scanf("%d", &nums[i]);
        }
        num_arrs[num_arr_index] = nums;
    }

    // ot men tolkova
}