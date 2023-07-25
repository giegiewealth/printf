#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(y) (void)(y)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 *struct Format - Struct op
 *@format: The format.
 *@function: The function associated.
 */
struct Format
{
    char format;
    int (*function)(va_list, char[], int, int, int, int);
};

/**
 *typedef struct Format Format_t - Struct op
 *@format: The format.
 *@function: The function associated.
 */
typedef struct Format Format_t;

int cus_printf(const char *cus_format, ...);
int handle_print(const char *fmt, int *i, va_list list,
                 char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print characters and strings */
int print_character(va_list types, char buffer[],
                    int flags, int width, int precision, int size);
int print_custom_string(va_list types, char buffer[],
                        int flags, int width, int precision, int size);
int print_percentage(va_list types, char buffer[],
                     int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_integer(va_list types, char buffer[],
                  int flags, int width, int precision, int size);
int print_binary_number(va_list types, char buffer[],
                        int flags, int width, int precision, int size);
int print_unsigned_integer(va_list types, char buffer[],
                           int flags, int width, int precision, int size);
int print_octal_number(va_list types, char buffer[],
                       int flags, int width, int precision, int size);
int print_hexadecimal_number(va_list types, char buffer[],
                             int flags, int width, int precision, int size);
int print_uppercase_hexadecimal(va_list types, char buffer[],
                                int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char map_to[],
                      char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters */
int print_non_printable_chars(va_list types, char buffer[],
                              int flags, int width, int precision, int size);

/* Function to print memory address */
int print_memory_address(va_list types, char buffer[],
                         int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int cus_get_flags(const char *cus_format, int *cus_i);
int cus_get_width(const char *cus_format, int *cus_i, va_list cus_list);
int cus_get_precision(const char *cus_format, int *cus_i, va_list cus_list);
int cus_get_size(const char *cus_format, int *cus_i);

/* Function to print string in reverse */
int print_reversed_string(va_list types, char buffer[],
                          int flags, int width, int precision, int size);

/* Function to print a string in rot 13 */
int print_rot13_string(va_list types, char buffer[],
                       int flags, int width, int precision, int size);

/* Width handler */
int handle_write_char(char c, char buffer[],
                      int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
                 int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
              int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
                  int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned(int is_negative, int ind,
                   char buffer[], int flags, int width, int precision, int size);

/** Utilities **/
int is_printable_char(char);
int append_hexadecimal_code(char, char[], int);
int is_digit_char(char);

/** Print buffer **/
void print_output_buffer(char buffer[], int *buff_ind);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* PRINT_UTILS_H */
