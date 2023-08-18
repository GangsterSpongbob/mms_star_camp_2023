#include <stdio.h>

#define MAX(x, y, z) (x) > (y) ? ((x) > (z) ? (x) : ((z) > (y) ? (z) : (y))) : ((y) > (z) ? (y) : (z))
#define MIN(x, y, z) (x) < (y) ? ((x) < (z) ? (x) : ((z) < (y) ? (z) : (y))) : ((y) < (z) ? (y) : (z))
#define SETBIT(mask, bit) mask | 1 << bit
#define CLEARBIT(mask, bit) mask & ~(1 << bit)
#define INVERSEBIT(mask, bit) mask ^ 1 << bit
#define CHECKBIT(mask, bit) !!(mask & 1 << bit)
#define SWAP(a, b)  \
    {               \
        int temp;   \
        temp = (a); \
        (a) = (b);  \
        (b) = temp; \
    }

int main(void)
{
    printf("%d\n", MAX(7, 2, 9));
    printf("%d\n", MIN(7, 2, 9));
    printf("%d\n", SETBIT(0, 3));
    printf("%d\n", CLEARBIT(63, 1));
    printf("%d\n", INVERSEBIT(63, 1));
    printf("%d\n", INVERSEBIT(0, 1));
    printf("%d\n", CHECKBIT(63, 1));
    printf("%d\n", CHECKBIT(0, 1));
    int a = 9, b = 3;
    SWAP(a, b);
    printf("%d, %d\n", a, b);

    return 0;
}