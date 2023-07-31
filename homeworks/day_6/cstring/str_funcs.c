#include "str_funcs.h"

int my_strlen(char *src)
{
    int len = 0;

    while (src[len++] != '\0')
        ;

    return --len;
}

void my_strcpy(char *src, char *dest)
{
    int index = 0;

    for (int i = 0; i < my_strlen(dest) + 1; i++)
    {
        src[i] = dest[i];
    }
}

int my_strcmp(char *lhs, char *rhs)
{
    int similar = 0;
    int min_len = my_strlen(lhs) < my_strlen(rhs) ? my_strlen(lhs) : my_strlen(rhs);

    for (int i = 0; i < min_len; i++)
    {
        if (lhs[i] == rhs[i])
        {
            similar++;
        }
        else
        {
            break;
        }
    }

    int modifier = my_strlen(lhs) > my_strlen(rhs) ? 1 : -1;

    return (my_strlen(lhs) > my_strlen(rhs) ? my_strlen(lhs) : my_strlen(rhs) - similar) * modifier;
}

void my_strcat(char *src, char *dest)
{
    for (int i = 0; i < my_strlen(src) + 1; i++)
    {
        dest[my_strlen(dest) + i] = src[i];
    }
}