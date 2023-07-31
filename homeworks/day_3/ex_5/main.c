#include <stdio.h>

void count_function_calls();

int main(void)
{
    count_function_calls();
    count_function_calls();
    count_function_calls();

    return 0;
}

void count_function_calls()
{
    static int call_counter = 0;
    ++call_counter;
    printf("%s%d%s\n", "Function called ", call_counter, " times");
}
