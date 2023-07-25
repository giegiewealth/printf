#include "main.h"

#define BUFF_SIZE 1024

/* Helper function to write characters to the output buffer */
static int write_chars_to_buffer(char buffer[], int start, int end, char c)
{
    for (int i = start; i < end; i++)
        buffer[i] = c;
    return end - start;
}

/* Helper function to write the final buffer to the output and reset it */
static int write_buffer(char buffer[], int length)
{
    int chars_written = write(1, buffer, length);
    buffer[0] = '\0'; // Reset the buffer
    return chars_written;
}

/* Helper function to write a number to the output buffer */
static int write_number_to_buffer(char buffer[], int number, int ind, char padd, char extra_c, int width)
{
    int length = ind + 1; // Calculate the length of the number

    if (extra_c != 0)
        length++;

    if (width > length)
    {
        int padd_start = 1;
        if (padd == '0')
            padd_start = 0;

        int padding_length = width - length;
        int padding_chars_written = write_chars_to_buffer(buffer, padd_start, padd_start + padding_length, padd);

        if (extra_c)
            buffer[--padd_start] = extra_c;

        if (padd_start == 0)
        {
            // If padding is added to the left of the number
            return write_buffer(buffer, padding_chars_written) +
                   write(1, &buffer[ind - padding_chars_written + 1], length - padding_chars_written);
        }
        else
        {
            // If padding is added to the right of the number
            return write(1, &buffer[ind], length) + write_buffer(buffer, padding_chars_written);
        }
    }

    if (extra_c)
        buffer[--ind] = extra_c;

    return write(1, &buffer[ind], length);
}

/* Function to handle writing a single character */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
    UNUSED(precision);
    UNUSED(size);

    char padd = (flags & F_ZERO) ? '0' : ' ';
    int i = 0;

    buffer[i++] = c;
    buffer[i] = '\0';

    if (width > 1)
    {
        int padding_chars_written = write_chars_to_buffer(buffer, i, width, padd);

        if (flags & F_MINUS)
        {
            // Left-align the character
            return write(1, &buffer[0], 1) + write_buffer(buffer, padding_chars_written);
        }
        else
        {
            // Right-align the character
            return write_buffer(buffer, padding_chars_written) + write(1, &buffer[0], 1);
        }
    }

    return write(1, &buffer[0], 1);
}

/* Function to write a signed number */
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
    char padd = (flags & F_ZERO) && !(flags & F_MINUS) ? '0' : ' ';
    char extra_c = 0;

    if (is_negative)
    {
        extra_c = '-';
    }
    else if (flags & F_PLUS)
    {
        extra_c = '+';
    }
    else if (flags & F_SPACE)
    {
        extra_c = ' ';
    }

    return write_number_to_buffer(buffer, ind, ind, padd, extra_c, width);
}

/* Function to write an unsigned number */
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
    char padd = (flags & F_ZERO) ? '0' : ' ';

    // The number is stored at the buffer's right and starts at position ind
    int length = ind + 1;
    UNUSED(is_negative);
    UNUSED(size);

    if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
    {
        return 0; // printf(".0d", 0) - no characters are printed
    }

    if (precision > 0 && precision < length)
    {
        padd = ' ';
    }

    while (precision > length)
    {
        buffer[--ind] = '0';
        length++;
    }

    return write_number_to_buffer(buffer, ind, ind, padd, 0, width);
}

/* Function to write a memory address */
int write_pointer(char buffer[], int ind, int length, int width, int flags)
{
    char padd = (flags & F_ZERO) ? '0' : ' ';
    char extra_c = 0;

    if (width > length)
    {
        int padding_chars_written = write_chars_to_buffer(buffer, 3, width, padd);

        buffer[1] = '0';
        buffer[2] = 'x';

        return write(1, &buffer[ind], length) + write_buffer(buffer, padding_chars_written);
    }

    buffer[--ind] = 'x';
    buffer[--ind] = '0';

    return write(1, &buffer[ind], length);
}
