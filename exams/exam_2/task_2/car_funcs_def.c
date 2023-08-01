#include "car_funcs.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int compare_models_asc(const void *model_1, const void *model_2)
{
    return -1 * strcmp(model_1, model_2);
}

int compare_models_desc(const void *model_1, const void *model_2)
{
    return strcmp(model_1, model_2);
}

int compare_max_speed_asc(const void *spd_1, const void *spd_2)
{
    return *(int *)spd_2 - *(int *)spd_1;
}

int compare_max_speed_desc(const void *spd_1, const void *spd_2)
{
    return *(int *)spd_1 - *(int *)spd_2;
}

int compare_price_asc(const void *price_1, const void *price_2)
{
    return *(int *)price_2 - *(int *)price_1;
}

int compare_price_desc(const void *price_1, const void *price_2)
{
    return *(int *)price_1 - *(int *)price_2;
}

int (*get_comparator(uint8_t n))(const void *, const void *)
{
    int (*cmp_funcs[6])(const void *, const void *);
    cmp_funcs[0] = compare_models_asc;
    cmp_funcs[1] = compare_models_desc;
    cmp_funcs[2] = compare_max_speed_asc;
    cmp_funcs[3] = compare_max_speed_desc;
    cmp_funcs[4] = compare_price_asc;
    cmp_funcs[5] = compare_price_desc;

    if (n < 6)
    {
        return cmp_funcs[n];
    }
    else
    {
        return NULL;
    }
}

car generate_random_car(int index)
{
    srand(time(NULL) + index);

    car random_car;

    uint8_t letters = rand() % 17; // number of letters up to 16
    uint8_t digits = rand() % 5;   // number of digits up to 4;

    for (uint8_t i = 0; i < letters; i++)
    {
        random_car.model[i] = (rand() % 2) * ('a' - 'A') + rand() % 27 + 'A'; // random capital or small letter
    }
    for (uint8_t i = 0; i < digits; i++)
    {
        random_car.model[letters + i] = rand() % 6 + 4 + '0'; // random digit from 4 to 9
    }
    random_car.model[letters + digits] = '\0';

    random_car.max_speed = rand() % 201 + 100;
    random_car.price = rand() % 98999 + (double)((rand() % 100) / 100) + 1000;

    return random_car;
}

void print_car(car current_car)
{
    printf("%s%s%s%d%s%lf\n", "Car model is ", current_car.model, ", car max speed is ", current_car.max_speed, " and car price is ", current_car.price);
}