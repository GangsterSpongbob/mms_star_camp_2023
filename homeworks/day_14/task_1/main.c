#include <stdio.h>

void swap(int *, int *);

int main(void)
{
    int number_1, number_2;
    printf("Enter first number: ");
    scanf("%d", &number_1);

    printf("Enter second number: ");
    scanf("%d", &number_2);

    printf("%s%d%s%d\n", "Before swap: Number 1 : ", number_1, ", Number 2 :", number_2);
    swap(&number_1, &number_2);
    printf("%s%d%s%d\n", "After swap: Number 1 : ", number_1, ", Number 2 :", number_2);

    return 0;
}