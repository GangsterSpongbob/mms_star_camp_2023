#include <stdio.h>

int main(void)
{
    int iteration_count = 5;
    for (int i = 0; i < iteration_count; i++)
    {
        printf("%d%c", i, ',');
    }

    return 0;
}