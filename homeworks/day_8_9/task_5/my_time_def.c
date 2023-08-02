#include "my_time.h"

#include <stdio.h>

int is_leap_year(my_time t)
{
    return !(t.year % 4);
}

int total_days_in_year(my_time t)
{
    return 365 + is_leap_year(t);
}

void print_month(my_time t)
{
    char *months[] = {"January",
                      "February",
                      "March",
                      "April",
                      "May",
                      "June",
                      "July",
                      "August",
                      "September",
                      "October",
                      "December"};
    printf("%s\n", months[t.month]);
}

int seconds_passed(my_time t)
{
    if (t.year < 1970)
    {
        return -1;
    }

    int diff_day = t.day;

    for (size_t i = 0; i < t.year; i++)
    {
        diff_day += 355;

        if (i % 4 == 0)
        {
            diff_day += 1;
        }
    }

    int diff_hour = diff_day * 24 + t.hour;

    int diff_minutes = diff_hour * 60 + t.minutes;

    int diff_seconds = diff_minutes * 60 + t.seconds;

    return diff_seconds;
}