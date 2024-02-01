#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int handle_format_spec(char specifier, va_list all_args_list);
int write_char(char ch);
int write_str(const char *str)
#endif /* MAIN_H */

