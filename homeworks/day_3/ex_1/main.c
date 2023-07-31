#include "utils.h"

#define LOWER_BOUND_VALUE 5
#define UPPER_BOUND_VALUE 20

#define LBV LOWER_BOUND_VALUE
#define UBV UPPER_BOUND_VALUE

int main(void)
{
    for (int i = 0; i < 10; i++)
        print_number_info(i, LBV, UBV);

    int index = 0;
    while (index < 10)
        print_number_info(index++, LBV, UBV);

    index = 0;
    do
        print_number_info(index++, LBV, UBV);
    while (index < 10);

    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
            break;
        print_number_info(i, LBV, UBV);
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 6)
            continue;
        print_number_info(i, LBV, UBV);
    }

    return 0;
}
