#include <stdio.h>

int main(void)
{
    int age = 25;
    int weight = 60;

    if (age < 18)
    {
        printf("You are underage. Thus you cannot vote or donate blood.\n");
    }
    else
    {
        if (weight >= 100)
        {
            printf("You are eligible to vote and donate blood.\n");
        }
        else
        {
            printf("You are eligible to vote, but not to donate blood.\n");
        }
    }

    return 0;
}