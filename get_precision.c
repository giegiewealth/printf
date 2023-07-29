#include "main.h"

/**
 * get_precision - Calculates the precision for printing...
 * @format: Formatted string in which to print the arguments...
 * @i: List of arguments to be printed....
 * @list: list of arguments.....
 *
 * Return: Precision.....
 */
int get_precision(const char *format, int *i, va_list list)
{
	int size_i = *i + 1;
	int precision = -1;

	if (format[size_i] != '.')
		return (precision);

	precision = 0;

	for (size_i += 1; format[size_i] != '\0'; size_i++)
	{
		if (is_digit(format[size_i]))
		{
			precision *= 10;
			precision += format[size_i] - '0';
		}
		else if (format[size_i] == '*')
		{
			size_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = size_i - 1;

	return (precision);
}
