#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - custom creation and implimentation of stdlib printf
 * @format: The format string.
 *
 * Return: The number of characters printed out (exceptnull byte).
 */

int _printf(const char *format, ...)

/**
 * write_char - Writes a single character to the standard output.
 * @ch: The character to be written.
 *
 * Return: The number of characters written (1).
 */

int write_char(char ch)
{
	write(1, &ch, 1);
	return (1);
}

/**
 * write_str - Writes a string of characters to standard output.
 * @str: The string to be written.
 *
 * Return: The number of characters written (excluding the null byte).
 * If the input string is NULL, "(null)" is written instead.
 */
int write_str(const char *str)
{
	if (str == NULL)
	{
		return (write_str("(null)"));
	}
	int len = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		len++
	}
	return (len);

{
	int character_print = 0;
	va_list all_args_list;

	if (format == NULL)
	{
		return (-1); /*handles NULL format string*/
	}
	va_start(all_args_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			character_print += write_char(*format);
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					character_print += write_char(va_arg(all_args_list, int));
					break;
				case 's':
					character_print += write_str(va_arg(all_args_list, char *));
					break;
				case '%':
				character_print += write_char('%');
			}
			format++;
		}

	va_end(all_args_list);
	return (character_print);
}

