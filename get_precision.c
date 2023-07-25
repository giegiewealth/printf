#include "main.h"

/**
 * cus_get_precision - calculates precision
 * @cus_format: input string
 * @cus_i: list of args
 * @cus_list: list of args
 * Return: precision
 */
int cus_get_precision(const char *cus_format, int *cus_i, va_list cus_list)
{
    int cus_curr_i = *cus_i + 1;
    int cus_precision = -1;

    if (cus_format[cus_curr_i] != '.')
        return (cus_precision);

    cus_precision = 0;

    for (cus_curr_i += 1; cus_format[cus_curr_i] != '\0'; cus_curr_i++)
    {
        if (is_digit_char(cus_format[cus_curr_i]))
        {
            cus_precision *= 10;
            cus_precision += cus_format[cus_curr_i] - '0';
        }
        else if (cus_format[cus_curr_i] == '*')
        {
            cus_curr_i++;
            cus_precision = va_arg(cus_list, int);
            break;
        }
        else
            break;
    }
    *cus_i = cus_curr_i - 1;

    return (cus_precision);
}
