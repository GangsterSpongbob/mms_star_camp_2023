#include <stdio.h>

int main(void)
{
    int sample_int = 11;
    int *sample_ptr = &sample_int;

    printf("%s%d%s%p\n", "Original value is ", sample_int, " at adress ", sample_ptr);

    int copy_of_int = *sample_ptr;

    printf("%s%d\n", "Value of copy is ", copy_of_int);

    *sample_ptr = 14;

    printf("%s%d%s%p\n", "New value is ", sample_int, " at adress ", sample_ptr);

    return 0;
}