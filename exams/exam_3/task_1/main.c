#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#include "utils.h"

#define HEX 0
#define BIN 1

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        perror("Must provide argument and flag\n");
        exit(-1);
    }

    uint8_t mode = HEX;

    if (toupper(argv[2][1]) == 'H')
    {
        mode = HEX;
    }
    else if (toupper(argv[2][1] == 'B'))
    {
        mode = BIN;
    }
    else
    {
        perror("Invalid flag\n");
        exit(-1);
    }

    FILE *file_in;
    char current_char = 0;

    if ((file_in = fopen(argv[1], "r")) == NULL)
    {
        perror("Couldn't open file\n");
        exit(-1);
    }

    while (current_char != EOF)
    {
        current_char = fgetc(file_in);
        if (mode == BIN)
        {
            print_char_to_bin(current_char);
        }
        else if (mode == HEX)
        {
            print_char_to_hex(current_char);
        }
    }

    printf("\n");

    fclose(file_in);
}