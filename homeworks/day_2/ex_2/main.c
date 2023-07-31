#include <stdio.h>

int main(void)
{
    int binary = 0b00100101;
    int octal = 0617;
    int hexadecimal = 0x1D72F;

    printf("%s%d\n", "Binary number: ", binary);
    printf("%s%d\n", "Octal number: ", octal);
    printf("%s%d\n", "Hexadecimal number: ", hexadecimal);

    return 0;
}