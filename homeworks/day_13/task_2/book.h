#ifndef BOOK_H
#define BOOK_H

#include <stdint.h>

#define TITLE_LEN 150
#define AUTHOR_NAME_LEN 100

typedef struct Book
{
    char title[TITLE_LEN];
    char author_name[AUTHOR_NAME_LEN];
    uint16_t page_count;
    double price;
} book;

book generate_random_book(uint8_t);
void print_book(book);

int compare_title_asc(const void *, const void *);
int compare_title_desc(const void *, const void *);
int compare_author_name_asc(const void *, const void *);
int compare_author_name_desc(const void *, const void *);
int compare_page_count_asc(const void *, const void *);
int compare_page_count_desc(const void *, const void *);
int compare_price_asc(const void *, const void *);
int compare_price_desc(const void *, const void *);

#endif // BOOK_H