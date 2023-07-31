#include "utils.h"
#include "string.h"

#include <stdio.h>

#define VOWEL_COUNT 10

_Bool char_is_vowel(char check_if_vowel)
{
    char vowels[VOWEL_COUNT] = "aeiouAEIOU";

    for (size_t i = 0; i < 10; i++)
    {
        if (check_if_vowel == vowels[i])
        {
            return 1;
        }
    }

    return 0;
}

void print_line_consonants(char line[], size_t line_len)
{
    for (size_t i = 0; i < strlen(line); i++)
    {
        if (char_is_vowel(line[i]))
        {
            continue;
        }

        printf("%c", line[i]);
    }
}