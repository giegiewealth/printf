#include "main.h"

/**
 * cus_get_flags - Calculates active flags
 * @cus_format: Formatted string in which to print the arguments
 * @cus_i: Take a parameter.
 * Return: Flags:
 */
int cus_get_flags(const char *cus_format, int *cus_i)
{
/* - + 0 # ' ' */
/* 1 2 4 8 16 */
int cus_j, cus_curr_i;
int cus_flags = 0;
const char CUS_FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int CUS_FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (cus_curr_i = *cus_i + 1; cus_format[cus_curr_i] != '\0'; cus_curr_i++)
    {
for (cus_j = 0; CUS_FLAGS_CH[cus_j] != '\0'; cus_j++)
        {
if (cus_format[cus_curr_i] == CUS_FLAGS_CH[cus_j])
            {
cus_flags |= CUS_FLAGS_ARR[cus_j];
break;
}
{

if (CUS_FLAGS_CH[cus_j] == 0)
break;
    }

*cus_i = cus_curr_i - 1;

return (cus_flags);
}
