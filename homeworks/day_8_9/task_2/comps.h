#ifndef COMPS_H
#define COMPS_H

#include <stdint.h>

typedef struct Point
{
    double x;
    double y;
    double z;
} point;

typedef struct Human
{
    double weight_kg;
    uint16_t height_cm;
} human;

int compare_64_bit_ints(const void *, const void *);
int compare_distance_3d(const void *, const void *);
int compare_bmi(const void *, const void *);
int compare_positive_bit_count(const void *, const void *);

double calculate_distance(double, double, double);
uint8_t count_positive_bits(float);

#endif // COMPS_H