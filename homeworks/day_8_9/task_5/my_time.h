#ifndef MY_TIME_H
#define MY_TIME_H

#include <stdint.h>

typedef struct My_time
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minutes;
    uint8_t seconds;
} my_time;

int is_leap_year(my_time);
int total_days_in_year(my_time);
void print_month(my_time);
int seconds_passed(my_time);

#endif // MY_TIME_H