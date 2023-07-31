#include <stdio.h>

int main(void)
{
    __uint8_t a = 0b00000101;
    __uint8_t b = 0b00001001;

    printf("%s%d%s%d\n", "a is ", a, " and b is ", b);

    printf("%s%d\n", "a & b = ", a & b);
    printf("%s%d\n", "a | b = ", a | b);
    printf("%s%d\n", "a ^ b = ", a ^ b);

    printf("%s%d\n", "~a = ", ~a);
    printf("%s%d\n", "~b = ", ~b);

    printf("%s%d\n", "b << 1 = ", b << 1);
    printf("%s%d\n", "b >> 1 = ", b >> 1);

    return 0;
}