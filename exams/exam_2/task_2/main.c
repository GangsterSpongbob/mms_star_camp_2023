#include "car_funcs.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    car cars[MAX_CAR_ARR_LEN];
    for (uint8_t i = 0; i < MAX_CAR_ARR_LEN; i++)
    {
        cars[i] = generate_random_car(i);
    }

    int indicator;
    printf("Enter indicator from 1 to 6: ");
    scanf("%d", &indicator);
    indicator = 1;

    qsort(cars, MAX_CAR_ARR_LEN, sizeof(car), get_comparator(indicator));

    for (uint8_t i = 0; i < MAX_CAR_ARR_LEN; i++)
    {
        print_car(cars[i]);
    }

    return 0;
}