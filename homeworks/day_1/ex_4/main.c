#include <stdio.h>

int sample_integer = 2;

void sample_function(void);

int main(void)
{
    sample_function();
    printf("%s%d", "The variable outsdide the function is ", sample_integer);

    return 0;
}

void sample_function(void)
{
    printf("%s%d", "The variable inside the function is ", sample_integer);
}