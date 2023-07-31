#include <stdio.h>

void sample_function(void);

int main(void)
{
    sample_function();
    return 0;
}

void sample_function(void)
{
    int sample_integer = 7;
    printf("%s%d\n", "The variable inside the function equals ", sample_integer);
}