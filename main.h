#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

#define BUFF_SIZE 1024

/**
 * Flags definition
 */
#define PLUS_FLAG 1
#define SPACE_FLAG 2
#define HASH_FLAG 4
#define ZERO_FLAG 8
#define MINUS_FLAG 16

int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
int handle_specifier(const char *format, int *index, va_list args, char printf_output_array[], int flags, int width, int precision, int size);

int _printf(const char *format, ...); 

#endif /* MAIN_H */

