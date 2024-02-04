#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string.
 *
 * Return: The characters printed( Except null byte).
 */

int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	int chars_printed = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chars_printed++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					chars_printed += write_char(va_arg(args, int));
					break;
				case 's':
					chars_printed += write_str(va_arg(args, char));
					break;
				case '%':
					chars_printed += write_char('%');
					break;
				default:
					/* ignore unsuported specifier*/
					write_char('%');
					write_char(*format);
					chars_printed += 2;
			}
		}

		format++;
	}
	va_end(args);

	return (chars_printed);
}


/**
 * write_char - writes a single character to the std output.
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
 * write_str - Writes a string of chars to std output.
 * @str: The string to be written.
 *
 * Return: The number of characters written (except null byte).
 * If input string is NULL, "(null)" is written instead.
 */

int write_str(const char *str)
{
	if (str == NULL)
		return (write_str("(null)"));

	int len = 0;
	while (*str)

	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}
