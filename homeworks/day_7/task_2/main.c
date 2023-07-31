#include <stdio.h>

#include "io_funcs.h"

int main(int argv, char *argc[])
{
    printf("%d\n", evaluate_expression(argc[1]));
}