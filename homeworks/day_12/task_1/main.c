#include <stdio.h>
#include <time.h>
#include <stdarg.h>

int printf_time(const char *format, ...);
int print_cur_time(void);

int main(void)
{
    printf_time("%s%d\n", "The current time has been displayed. Now the number 10 will be displayed: ", 10);

    return 0;
}

int print_cur_time(void)
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("%s", asctime(timeinfo));

    return 0;
}

int printf_time(const char *format, ...)
{
    print_cur_time();

    va_list var_ptr;

    va_start(var_ptr, format);
    vprintf(format, var_ptr);

    return 1;
}