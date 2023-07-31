#include <stdio.h>

int main(void)
{
    int even_or_odd;
    int print_until;

    printf("Enter 0 or 1 for even or odd respectively and a number at which the loop breaks: ");
    scanf("%d %d", &even_or_odd, &print_until);

    for (int i = 0; i < 100; i++)
    {
        if (i == print_until)
        {
            break;
        }

        if (!even_or_odd && i % 2 == 1)
        {
            continue;
        }
        else if (even_or_odd && i % 2 == 0)
        {
            continue;
        }
    }

    return 0;
}