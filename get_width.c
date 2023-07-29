#include "main.h"

/**
 * get_width - Calculates the width for printing......
 * @format: Formatted string in which to print the arguments.......
 * @i: List of arguments to be printed.......
 * @list: list of arguments.......
 *
 * Return: width.......
 */
int get_width(const char *format, int *i, va_list list)
{
	int size_i;
	int width = 0;

	for (size_i = *i + 1; format[size_i] != '\0'; size_i++)
	{
		if (is_digit(format[size_i]))
		{
			width *= 10;
			width += format[size_i] - '0';
		}
		else if (format[size_i] == '*')
		{
			size_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = size_i - 1;

	return (width);
}
