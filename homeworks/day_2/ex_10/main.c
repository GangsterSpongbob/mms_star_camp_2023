#include <stdio.h>

#include "utils.h"

#define MAX_STR_SIZE 1024

int main(void)
{
    char line[MAX_STR_SIZE];

    while (fgets(line, sizeof(line), stdin))
    {
        print_line_consonants(line, MAX_STR_SIZE);
    }

    return 0;
}