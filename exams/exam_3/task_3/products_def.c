#include "products.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

void assign_char_arr(char dest[], char src[], uint16_t char_count)
{
    for (size_t i = 0; i < char_count; i++)
    {
        dest[i] = src[i];
    }
}

product generate_random_product(uint8_t randomizer)
{
    srand(time(NULL) + randomizer);

    product new_prod;
    new_prod.old_price = 4.99 + ((double)(rand() % 47) / 100) + rand() % 96;
    new_prod.new_price = 4.99 + ((double)(rand() % 47) / 100) + rand() % 96;
    new_prod.product_type = rand() % 5;
    assign_char_arr(new_prod.product_name, names[rand() % 11], 7);
    new_prod.id = randomizer;

    return new_prod;
}

void print_product(product *cur_prod)
{
    printf("%s%i%s%s%s%.2lf%s%.2lf%s%c\n",
           "Product No.", cur_prod->id,
           ": ", cur_prod->product_name,
           " with previous price ", cur_prod->old_price,
           " now costs ", cur_prod->new_price,
           ". Product type: ", types[cur_prod->product_type]);
}

void print_arr_of_products(product prods[], uint16_t prod_count)
{
    for (size_t i = 0; i < prod_count; i++)
    {
        print_product(&prods[i]);
    }
}

int compare_products(const void *l_p, const void *r_p)
{
    product *left_prod = (product *)l_p;
    product *right_prod = (product *)r_p;

    double left_change = left_prod->new_price - left_prod->old_price;
    double right_change = right_prod->new_price - right_prod->old_price;

    if (left_change - right_change > 0.01 || left_change - right_change < -0.01)
    {
        return left_change - right_change > 0 ? 1 : -1;
    }

    if (left_prod->product_type - right_prod->product_type)
    {
        return left_prod->product_type - right_prod->product_type;
    }

    if (strcmp(left_prod->product_name, right_prod->product_name) != 0)
    {
        return strcmp(left_prod->product_name, right_prod->product_name);
    }

    return right_prod->id - left_prod->id;
}

void write_prod_to_file(product *cur_prod, FILE *file_out)
{
    fprintf(file_out, "%i %s %.2lf %.2lf %c\n",
            cur_prod->id,
            cur_prod->product_name,
            cur_prod->old_price,
            cur_prod->new_price,
            types[cur_prod->product_type]);
}

void write_arr_of_products(product prod_arr[], uint16_t prod_count, FILE *file_out)
{
    for (size_t i = 0; i < prod_count; i++)
    {
        write_prod_to_file(prod_arr + i, file_out);
    }
}

void print_products_from_file(FILE *file_in, uint16_t prod_count)
{
    for (size_t i = 0; i < prod_count; i++)
    {
        product cur_prod;
        fscanf(file_in, "%i %s %lf %lf %c\n", &cur_prod.id, cur_prod.product_name, &cur_prod.old_price, &cur_prod.new_price, &cur_prod.product_type);
        print_product(&cur_prod);
    }
}