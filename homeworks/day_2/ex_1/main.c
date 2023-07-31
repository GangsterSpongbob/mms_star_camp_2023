#include <stdio.h>

int main(void)
{
    char sample_char = 'f';
    int sample_int = 81;
    float sample_float = 5.56;
    double sample_double = 7.1457534584;
    _Bool sample_bool = 1;

    printf("%s%c\n", "Char: ", sample_char);
    printf("%s%d\n", "Int: ", sample_int);
    printf("%s%f\n", "Float: ", sample_float);
    printf("%s%lf\n", "Double: ", sample_double);
    printf("%s%d\n", "Bool: ", sample_bool);

    return 0;
}