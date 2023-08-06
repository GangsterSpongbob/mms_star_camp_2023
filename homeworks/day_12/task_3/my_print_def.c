#include "my_print.h"

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>

int my_printf(const char *format, ...)
{
    uint8_t printed_count = 0;
    va_list str_ptr;
    va_start(str_ptr, format);

    size_t index = 0;
    while (format[index] != '\0')
    {
        if (format[index] == '%')
        {
            index++;
            if (format[index] == 'd')
            {
                int current_el = va_arg(str_ptr, int);
                printed_count += print_int(current_el);
            }
            else if (format[index] == 'f')
            {
                float current_el = va_arg(str_ptr, double);
                printed_count += print_float(current_el);
            }
            else if (format[index] == 'c')
            {
                char current_el = va_arg(str_ptr, int);
                printed_count += putc(current_el, stdout);
            }
            index++;
        }
        else
        {
            putc(format[index++], stdout);
        }
    }

    return printed_count;
}

int print_int(int pr)
{
    char str[16] = {};
    int index = 0;

    while (pr != 0)
    {
        str[index++] = pr % 10 + '0';
        pr /= 10;
    }

    while (index >= 0)
    {
        putc(str[index--], stdout);
    }

    return 1;
}

int print_float(float pr)
{
    char str[16] = {};
    int index = 0;

    int whole_part = (int)pr;
    uint8_t decimal_point_index = 0;

    while (whole_part > 0)
    {
        whole_part /= 10;
        decimal_point_index++;
    }

    int temp = (int)(pr * 10000);

    while (temp % 10 == 0)
    {
        temp /= 10;
    }

    while (temp != 0)
    {
        str[index++] = temp % 10 + '0';
        temp /= 10;
    }

    decimal_point_index = index - decimal_point_index - 1;

    while (index >= 0)
    {
        if (index == decimal_point_index)
        {
            putc('.', stdout);
        }

        putc(str[index--], stdout);
    }

    return 1;
}