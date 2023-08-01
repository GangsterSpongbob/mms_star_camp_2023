#include "maps.h"

char map_to_symbol(char c)
{
    char map[11] = {"!#/~='\\>.,"};
    return map[c - '0'];
}

void run_map_on_str(char *str)
{
    for (unsigned int i = 0; i < MAX_NUM_LEN; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }

        if (i % 2 == 0)
        {
            str[i] += ('A' - '0');
        }
        else
        {
            str[i] = map_to_symbol(str[i]);
        }
    }
}