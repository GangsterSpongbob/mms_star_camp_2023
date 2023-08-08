#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <stdint.h>
#include <stdio.h>

static char names[10][7] = {"Zele",
                            "Kartof",
                            "Morkov",
                            "Tikva",
                            "Domat",
                            "Meso",
                            "Sirene",
                            "Olio",
                            "Ocet",
                            "Voda"}; // nz i az veche

static char types[4] = {'A', 'B', 'C', 'D'};

typedef struct Product
{
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[7];
} product;

product generate_random_product(uint8_t);
void assign_char_arr(char[], char[], uint16_t);
void print_product(product *);
void print_arr_of_products(product[], uint16_t);
int compare_products(const void *, const void *);
void write_prod_to_file(product *, FILE *);
void write_arr_of_products(product[], uint16_t, FILE *);
void print_products_from_file(FILE *, uint16_t);

#endif //  PRODUCTS_H