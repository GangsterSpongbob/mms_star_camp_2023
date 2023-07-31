#include <stdio.h>

int main(void)
{
    int whole_number_1 = 166;
    int whole_number_2 = 2;
    char result_char = whole_number_1 / whole_number_2;

    printf("%s%c\n", "The resulting char is: ", (char)(result_char));

    return 0;
}