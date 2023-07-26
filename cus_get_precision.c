#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @cus: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *cus, va_list list)
{
	int curr_cus = *cus + 1;
	int precision = -1;

	if (format[curr_cus] != '.')
		return (precision);

	precision = 0;

	while (format[curr_cus] != '\0')
	{
		if (is_digit(format[curr_cus]))
		{
			precision *= 10;
			precision += format[curr_cus] - '0';
		}
		else if (format[curr_cus] == '*')
		{
			curr_cus++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;

		curr_cus++;
	}

	*cus = curr_cus - 1;

	return (precision);
}
