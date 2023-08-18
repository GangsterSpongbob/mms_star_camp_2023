#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"
#include "double_link.h"

#define BOOK_ARR_COUNT 10

int main(void)
{
    book b_arr[BOOK_ARR_COUNT];

    for (size_t i = 0; i < BOOK_ARR_COUNT; i++)
    {
        b_arr[i] = generate_random_book(i);
    }

    qsort(b_arr, BOOK_ARR_COUNT, sizeof(book), compare_title_asc);

    for (size_t i = 0; i < 10; i++)
    {
        print_book(b_arr[i]);
    }
    printf("\n\n\n\n");

    linked_list book_list = init_list();
    for (size_t i = 0; i < BOOK_ARR_COUNT; i++)
    {
        push_back(b_arr[i], &book_list);
    }

    print_linked_list(&book_list);

    deinit_list(&book_list);

    return 0;
}