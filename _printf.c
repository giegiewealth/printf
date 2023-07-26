#include "main.h"

void print_buffer(char cus[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i = 0, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char cus[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			cus[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(cus, &buff_ind);
			/* write(1, &format[i], 1); */
			printed_chars++;
		}
		else
		{
			print_buffer(cus, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, cus,
					       flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
		i++;
	}

	print_buffer(cus, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @cus: Array of chars
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char cus[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &cus[0], *buff_ind);

	*buff_ind = 0;
}
