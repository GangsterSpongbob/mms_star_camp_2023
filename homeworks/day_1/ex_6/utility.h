#include <stdio.h>

#define DEBUG
void foo(void)
{
#ifdef DEBUG
    printf("Debug mode is on.\n");
#else
    printf("Debug mode is off.\n");
#endif
}