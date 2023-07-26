#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @cus: Pointer to the current index in the format string
 * Return: Flags:
 */
int get_flags(const char *format, int *cus)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, curr_b;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	curr_b = *cus + 1;

	while (format[curr_b] != '\0')
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
		{
			if (format[curr_b] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}
		}

		if (FLAGS_CH[a] == 0)
			break;

		curr_b++;
	}

	*cus = curr_b - 1;

	return (flags);
}
