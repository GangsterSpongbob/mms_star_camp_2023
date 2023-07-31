#include <stdio.h>

int main(void)
{
    int age;
    double weight;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter weight: ");
    scanf("%lf", &weight);

    if (age < 18)
    {
        printf("Underage. Cannot donate blood or vote\n");
    }
    else if (weight < 100)
    {
        printf("Can donate blood\n");
    }
    else
    {
        printf("Can vote\n");
    }

    return 0;
}