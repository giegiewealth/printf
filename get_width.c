#include "main.h"

/**
 * cus_get_width - Calculates the width for printing
 * @cus_format: Formatted string in which to print the arguments.
 * @cus_i: List of arguments to be printed.
 * @cus_list: List of arguments.
 *
 * Return: Width.
 */
int cus_get_width(const char *cus_format, int *cus_i, va_list cus_list)
{
    int cus_curr_i;
    int cus_width = 0;

    for (cus_curr_i = *cus_i + 1; cus_format[cus_curr_i] != '\0'; cus_curr_i++)
    {
        if (is_digit_char(cus_format[cus_curr_i]))
        {
            cus_width *= 10;
            cus_width += cus_format[cus_curr_i] - '0';
