#include <stdio.h>

int main(void)
{
    int whole_number_1;
    int whole_number_2;

    printf("Enter two numbers separated by a space: ");
    scanf("%d %d", &whole_number_1, &whole_number_2);

    int sum = whole_number_1 + whole_number_2;
    printf("%s%d%s%d%s%d\n", "The sum of ", whole_number_1, " and ", whole_number_2, " is ", sum);

    return 0;
}