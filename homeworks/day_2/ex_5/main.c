#include <stdio.h>

int main(void)
{
    char c;

    short s;
    int i;
    long l;
    long long ll;

    float f;
    double d;

    printf("%s%lu%s\n", "Size of char: ", sizeof(c), " bytes");
    printf("%s%lu%s\n", "Size of short: ", sizeof(s), " bytes");
    printf("%s%lu%s\n", "Size of int: ", sizeof(i), " bytes");
    printf("%s%lu%s\n", "Size of long: ", sizeof(l), " bytes");
    printf("%s%lu%s\n", "Size of long long: ", sizeof(ll), " bytes");
    printf("%s%lu%s\n", "Size of float: ", sizeof(f), " bytes");
    printf("%s%lu%s\n", "Size of double: ", sizeof(d), " bytes");

    return 0;
}