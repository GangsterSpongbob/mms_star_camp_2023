#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    double *ptr = calloc(n, sizeof(double));

    for (int i = 0; i < n; i++)
    {
        ptr[i] = (double)(rand() % 1001) / 1000;
    }

    int m;
    scanf("%d", &m);

    double *new_ptr = realloc(ptr, (n + m) * sizeof(double));
    if (new_ptr == NULL)
    {
        free(ptr);
        return 0;
    }
    else
    {
        ptr = new_ptr;
    }

    for (int i = n; i < n + m; i++)
    {
        ptr[i] = 1 + (double)(rand() % 1001) / 1000;
    }

    int p;
    scanf("%d", &p);

    new_ptr = realloc(ptr, (n + m + p) * sizeof(double));
    if (new_ptr == NULL)
    {
        free(ptr);
        return 0;
    }
    else
    {
        ptr = new_ptr;
    }

    for (int i = n + m; i < n + m + p; i++)
    {
        ptr[i] = 2 + (double)(rand() % 1001) / 1000;
    }

    for (int i = 0; i < n + m + p; i++)
    {
        printf("%lf ", ptr[i]);
    }
    printf("\n");

    free(ptr);
}
