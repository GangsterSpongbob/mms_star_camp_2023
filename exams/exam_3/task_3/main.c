#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "products.h"

#define ARR_LEN 40

int main(void)
{
    product prod_list[ARR_LEN];
    for (size_t i = 0; i < ARR_LEN; i++)
    {
        prod_list[i] = generate_random_product(i);
    }

    print_arr_of_products(prod_list, ARR_LEN);

    qsort(prod_list, ARR_LEN, sizeof(product), compare_products);

    print_arr_of_products(prod_list, ARR_LEN);

    FILE *file_out;
    file_out = fopen("output.bin", "wb");

    write_arr_of_products(prod_list, ARR_LEN, file_out);

    fclose(file_out);

    return 0;
}