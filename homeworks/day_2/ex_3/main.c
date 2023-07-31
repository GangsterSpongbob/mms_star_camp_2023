#include <stdio.h>

int power(int, int);

int main(void)
{
    int whole_number = 511;
    int base = 10;
    int result = 0;
    int place_value = 0;

    while (whole_number > 0)
    {
        int digit = whole_number % base;
        result += digit * power(base, place_value);
        place_value++;
        whole_number /= base;
    }

    printf("%s%d\n", "Result is: ", result);

    return 0;
}

int power(int base, int exponent)
{
    int result = 1;

    for (size_t i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}