#include "main.h"

/**
 * cus_printf - duplicate printf function
 * @cus_format: input string
 * Return: number of characters printed
 */

int cus_printf(const char *cus_format, ...)
{
	int cus_i, cus_printed = 0, cus_printed_chars = 0;
	int cus_flags, cus_width, cus_precision, cus_size, cus_buff_ind = 0;

	va_list cus_args;

	char cus_buffer[BUFF_SIZE];

	if (cus_format == NULL)
		return (-1);

	va_start(cus_args, cus_format);

	for (cus_i = 0; cus_format && cus_format[cus_i] != '\0'; cus_i++)
	{
		if (cus_format[cus_i] != '%')
		{
			cus_buffer[cus_buff_ind++] = cus_format[cus_i];
			if (cus_buff_ind == BUFF_SIZE)
				print_buffer(cus_buffer, &cus_buff_ind);
			cus_printed_chars++;
		}
		else
		{
			print_buffer(cus_buffer, &cus_buff_ind);
			cus_flags = get_flags(cus_format, &cus_i);
			cus_width = get_width(cus_format, &cus_i, cus_args);
			cus_precision = get_precision(cus_format, &cus_i, cus_args);
			cus_size = get_size(cus_format, &cus_i);
			++cus_i;
			cus_printed = handle_print(cus_format, &cus_i, cus_args, cus_buffer,
					cus_flags, cus_width, cus_precision, cus_size);
			if (cus_printed == -1)
				return (-1);
			cus_printed_chars += cus_printed;
		}
	}
	print_buffer(cus_buffer, &cus_buff_ind);
	va_end(cus_args);

	return (cus_printed_chars);
}

