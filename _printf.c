#include "main.h"
#include <stdarg.h>
#include <unistd.h>

void flush_buffer(char printf_output_array[], int *printf_index);
/**
 * _printf - custom creation and implimentation of stdlib printf
 * @format: The format string.
 *
 * Return: The number of characters printed out (exceptnull byte).
 */

int _printf(const char *format, ...)

{
	int a, printed = 0, chars_to_print = 0;
	int flags, width, precision, size, printf_index = 0;
	va_list list;
	char printf_output_array[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			printf_output_array[printf_index++] = format[a];
			if (printf_index == BUFF_SIZE)
				flush_buffer(printf_output_array, &printf_index);
			chars_to_print++;
		}

		else
		{
			flush_buffer(printf_output_array, &printf_index);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			size = get_size(format, &a);
			++a;
			printed = handle_specifier(format, &a, list, printf_output_array, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_to_print += printed;
		}
	}

	flush_buffer(printf_output_array, &printf_index;

	va_end(list);

	return (chars_to_print);
}

/**
 * flush_buffer - Prints buffer contents
 * @printf_output: Array of chars
 * @printf_index: Index representing length and point to add next char.
 */

void flush_buffer(char printf_output[], int *printf_index)
{
	if (*printf_index > 0)
	write(1, &printf_output[0], *printf_index);

	*printf_index = 0;
}
