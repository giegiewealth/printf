#include "main.h"

/**
 * cus_get_size - calculate the size
 * @cus_format: input string
 * @cus_i: list of args
 * Return: size
 */

int cus_get_size(const char *cus_format, int *cus_i)
{
    int cus_curr_i = *cus_i + 1;
    int cus_size = 0;

    if (cus_format[cus_curr_i] == 'l')
        cus_size = S_LONG;
    else if (cus_format[cus_curr_i] == 'h')
        cus_size = S_SHORT;

    if (cus_size == 0)
        *cus_i = cus_curr_i - 1;
    else
        *cus_i = cus_curr_i;
    return (cus_size);
}

