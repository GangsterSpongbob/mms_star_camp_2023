#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%s%lf\n", "Sum of arguments is ", sum_of_cli_input(argc, argv));

    return 0;
}