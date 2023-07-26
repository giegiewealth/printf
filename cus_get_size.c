#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @cus: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *cus)
{
	int curr_a = *cus + 1;
	int size = 0;

	while (format[curr_a] == 'l' || format[curr_a] == 'h')
	{
		if (format[curr_a] == 'l')
			size = S_LONG;
		else if (format[curr_a] == 'h')
			size = S_SHORT;

		if (size == 0)
			*cus = curr_a - 1;
		else
			*cus = curr_a;

		curr_a++;
	}

	return (size);
}
