#include "main.h"

/**
 * get_width - Extracts and returns the width from the format string.
 * @format: The format string.
 * @index: A pointer to the current position in the format string.
 * @args: The va_list of arguments.
 *
 * Return: The extracted width.
 */

int get_width(const char *format, int *index, va_list args)
{
	int width = 0;

	while (format[*index] >= '0' && format[*index] <= '9')
	{
		width = width * 10 + (format[*index] - '0');
		(*index)++;
	}

	if (format[*index] == '*')
	{
		width = va_arg(args, int);
		(*index)++;
	}

	return (width);
}
