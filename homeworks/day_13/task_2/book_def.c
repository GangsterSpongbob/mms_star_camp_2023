#include "book.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdio.h>

book generate_random_book(uint8_t randomizer)
{
    srand(time(NULL) + randomizer);
    book new_book;

    uint8_t title_char_count = rand() % 11 + 10;
    uint8_t name_char_count = rand() % 11 + 10;

    for (size_t i = 0; i < title_char_count; i++)
    {
        new_book.title[i] = 'A' + rand() % 26 + rand() % 2 * ('a' - 'A');
    }
    new_book.title[title_char_count] = '\0';
    for (size_t i = 0; i < name_char_count; i++)
    {
        new_book.author_name[i] = 'A' + rand() % 26 + rand() % 2 * ('a' - 'A');
    }
    new_book.author_name[name_char_count] = '\0';

    new_book.page_count = rand() % 1996 + 5;
    new_book.price = rand() % 1000 + ((double)(rand() % 100) / 100);

    return new_book;
}

void print_book(book current_book)
{
    printf("%s%s%s%s%s%d%s%.2lf\n",
           "Book \"", current_book.title,
           "\" written by ", current_book.author_name,
           ". Pages: ", current_book.page_count,
           "; Price: ", current_book.price);
}

int compare_title_asc(const void *lhs, const void *rhs)
{
    return strcmp(lhs, rhs);
}

int compare_title_desc(const void *lhs, const void *rhs)
{
    return -1 * strcmp(lhs, rhs);
}

int compare_author_name_asc(const void *lhs, const void *rhs)
{
    return strcmp(lhs, rhs);
}

int compare_author_name_desc(const void *lhs, const void *rhs)
{
    return -1 * strcmp(lhs, rhs);
}

int compare_page_count_asc(const void *lhs, const void *rhs)
{
    return *(int *)lhs - *(int *)rhs;
}

int compare_page_count_desc(const void *lhs, const void *rhs)
{
    return *(int *)rhs - *(int *)lhs;
}

int compare_price_asc(const void *lhs, const void *rhs)
{
    double diff = *(double *)lhs - *(double *)rhs;
    if (diff > -0.00001 && diff < 0.00001)
    {
        return 0;
    }

    return diff > 1 ? 1 : -1;
}

int compare_price_desc(const void *lhs, const void *rhs)
{
    double diff = *(double *)rhs - *(double *)lhs;
    if (diff > -0.00001 && diff < 0.00001)
    {
        return 0;
    }

    return diff > 1 ? 1 : -1;
}