#include <stdio.h>

int main(void)
{
    int sample_number = 57;
    int base = 2;

    while (sample_number > 0)
    {
        int remainder = sample_number % base;
        printf("%d%s%d\n", sample_number, " - remainder: ", remainder);
        sample_number /= base;
    }

    return 0;
}