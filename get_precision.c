#include "main.h"

/**
 * get_precision - Extracts and returns the precision from the format string.
 * @format: The format string.
 * @index: A pointer to the current position in the format string.
 * @args: The va_list of arguments.
 *
 * Return: The extracted precision.
 */

int get_precision(const char *format, int *index, va_list args)
{
	int precision = -1; /* default precision value*/

	if (format[*index] == '.')
	{
		(*index)++;

		if (format[*index] == '*')
		{
			precision = va_arg(args, int);
			(*index)++;
		}
		else
		{
			precision = 0;

			while (format[*index] >= '0' && format[*index] <= '9')
			{
				precision = precision * 10 + (format[*index] - '0');
				(index)++;
			}
		}
	}

	return (precision);
}
