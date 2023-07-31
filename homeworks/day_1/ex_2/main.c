#include <stdio.h>

int square(const int);

int main(void)
{
    int num = 5;
    printf("%d%s%d\n", num, " squared is ", square(num));
    return 0;
}

int square(const int num)
{
    return num * num;
}