#include <stdio.h>
#include <stdint.h>

#define TYPE_INT 1
#define TYPE_CHAR 2
#define TYPE_DOUBLE 3
#define TYPE_FLOAT 4
#define TYPE_UINT8_T 5
#define TYPE_UINT16_T 6
#define TYPE_UINT32_T 7
#define TYPE_UINT64_T 8

void print_value(const void *, uint8_t);

int main(void)
{
    int num = 11;
    print_value(&num, TYPE_INT);

    char ch = 'A';
    print_value(&ch, TYPE_CHAR);

    double d = 1.64563;
    print_value(&d, TYPE_DOUBLE);

    float f = 6.2;
    print_value(&f, TYPE_FLOAT);

    return 0;
}

void print_value(const void *value_ptr, uint8_t flag)
{
    switch (flag)
    {
    case TYPE_INT:
        printf("%d\n", *(int *)(value_ptr));
        break;

    case TYPE_CHAR:
        printf("%c\n", *(char *)(value_ptr));
        break;

    case TYPE_DOUBLE:
        printf("%lf\n", *(double *)(value_ptr));
        break;

    case TYPE_FLOAT:
        printf("%f\n", *(float *)(value_ptr));
        break;

    case TYPE_UINT8_T:
        printf("%d\n", *(int *)(value_ptr));
        break;

    case TYPE_UINT16_T:
        printf("%d\n", *(int *)(value_ptr));
        break;

    case TYPE_UINT32_T:
        printf("%d\n", *(int *)(value_ptr));
        break;

    case TYPE_UINT64_T:
        printf("%d\n", *(int *)(value_ptr));
        break;

    default:
        break;
    }
}