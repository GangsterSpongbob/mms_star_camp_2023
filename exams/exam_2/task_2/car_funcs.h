#ifndef CAR_FUNCS_H
#define CAR_FUNCS_H

#include <stdint.h>

#define MAX_CAR_NAME 20
#define MAX_CAR_ARR_LEN 10

typedef struct Car
{
    char model[MAX_CAR_NAME];
    uint8_t max_speed;
    double price;
} car;

int compare_models_asc(const void *, const void *);
int compare_models_desc(const void *, const void *);
int compare_max_speed_asc(const void *, const void *);
int compare_max_speed_desc(const void *, const void *);
int compare_price_asc(const void *, const void *);
int compare_price_desc(const void *, const void *);

int (*get_comparator(uint8_t))(const void *, const void *);
car generate_random_car(int);
void print_car(car);

#endif // CAR_FUNCS_H