#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"

#define BOOK_ARR_COUNT 10

int main(void)
{
    book b_arr[BOOK_ARR_COUNT];

    for (size_t i = 0; i < BOOK_ARR_COUNT; i++)
    {
        b_arr[i] = generate_random_book(i);
    }

    qsort(b_arr, BOOK_ARR_COUNT, sizeof(book), compare_title_asc);

    for (size_t i = 0; i < BOOK_ARR_COUNT; i++)
    {
        print_book(b_arr[i]);
    }

    return 0;
}