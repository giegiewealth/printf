#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @cus: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *cus, va_list list)
{
	int curr_i;
	int width = 0;

	while (format[*cus + 1] != '\0')
	{
		curr_i = *cus + 1;
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			*cus = curr_i + 1;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*cus = curr_i - 1;

	return (width);
}
