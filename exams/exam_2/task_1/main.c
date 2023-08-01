#include <stdio.h>

#include "maps.h"

#define MAX_NUM_LEN 500

int main(void)
{
    char input[MAX_NUM_LEN];

    printf("%s%d%s", "Enter number up to ", MAX_NUM_LEN, " characters: ");
    scanf("%s", input);

    run_map_on_str(input);

    printf("%s\n", input);

    return 0;
}