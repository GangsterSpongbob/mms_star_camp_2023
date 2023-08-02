#include "comps.h"

#include <stdint.h>
#include <math.h>

int compare_64_bit_ints(const void *lhs_int, const void *rhs_int)
{
    return *(uint64_t *)lhs_int - *(uint64_t *)rhs_int;
}

int compare_distance_3d(const void *lhs_point, const void *rhs_point)
{
    point *temp_1 = (point *)lhs_point;
    point *temp_2 = (point *)rhs_point;

    double dist_lhs = calculate_distance(temp_1->x, temp_1->y, temp_1->z);
    double dist_rhs = calculate_distance(temp_2->x, temp_2->y, temp_2->z);

    return !!(dist_lhs - dist_rhs); // to bool to avoid loss of information
}

int compare_bmi(const void *lhs_human, const void *rhs_human)
{
    human *temp_1 = (human *)lhs_human;
    human *temp_2 = (human *)rhs_human;

    return !!(temp_1->weight_kg / temp_1->height_cm - temp_2->weight_kg / temp_2->height_cm);
}

int compare_positive_bit_count(const void *lhs_float, const void *rhs_float)
{
    return count_positive_bits(*(float *)lhs_float) - count_positive_bits(*(float *)rhs_float);
}

uint8_t count_positive_bits(float cnt)
{
    uint8_t counter = 0;
    while (cnt)
    {
        uint32_t bit_representation = *(uint32_t *)&cnt;
        counter += bit_representation & 1;
        bit_representation = bit_representation >> 1;
        cnt = *(float *)&bit_representation;
    }

    return counter;
}

double calculate_distance(double x, double y, double z)
{
    return sqrt(x * x + y * y + z * z);
}