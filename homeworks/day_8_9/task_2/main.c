#include <stdio.h>
#include <stdint.h>

#include "utils.h"
#include "comps.h"

int main(void)
{
    int arr[] = {1, 2, -1, 3, 5, 11, 12, 13, 2, 100, 22};

    int *max = find_max(arr, sizeof(arr) / sizeof(int), sizeof(int), cmp_int);
    printf("%d\n", *max); // 100

    uint64_t arr_2[] = {1, 2, 3, 122, 6512, 3, 4, 231};

    int *max_2 = find_max(arr_2, sizeof(arr_2) / sizeof(uint64_t), sizeof(uint64_t), compare_64_bit_ints);
    printf("%d\n", *max_2); // 6512

    point p_1 = {1.0, 1.0, 1.0};
    point p_2 = {2.0, 3.1, 1.1};
    point p_3 = {6.5, 0.7, 4.5};
    point p_4 = {-1.0, 0.0, 2.3};
    point arr_3[] = {p_1, p_2, p_3, p_4};

    int *max_3 = find_max(arr_3, sizeof(arr_3) / sizeof(point), sizeof(point), compare_distance_3d);
    printf("%d\n", *max_3); // idk

    human h_1 = {80.1, 176};
    human h_2 = {102.5, 191};
    human h_3 = {65.0, 185};
    human h_4 = {91.7, 159};
    human arr_4[] = {h_1, h_2, h_3, h_4};

    int *max_4 = find_max(arr_4, sizeof(arr_4) / sizeof(human), sizeof(human), compare_bmi);
    printf("%d\n", *max_4); // idk

    float arr_5[] = {1.243, 124.5145, 5264.262, 56357.256, 256.6524};

    int *max_5 = find_max(arr_5, sizeof(arr_5) / sizeof(float), sizeof(float), compare_positive_bit_count);
    printf("%d\n", *max_5); // idk

    return 0;
}