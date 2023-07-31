#include <stdio.h>

int is_odd(int number)
{
    return number % 2;
}

int main(void)
{
    int number = 5;
    if (is_odd(number))
    {
        printf("%d%s\n", number, "Is odd\n");
    }
    else
    {
        printf("%d%s\n", number, "Is even\n");
    }
}