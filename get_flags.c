#include "main.h"

/**
 * get_flags - Extracts and returns flags from the format string.
 * @format: The format string.
 * @index: A pointer to the current index in the format string.
 *
 * Return: Flags value.
 */

int get_flags(const char *format, int *index)
{
	int flags = 0;

	while (format[*index] == '+' || format[*index] == ' ' || format[*index] == '#' || format[*index] == '0' || format[*index] == '-')
	{
		if (format[*index] == '+')
			flags |= PLUS_FLAG;
		else if (format[*index] == ' ')
			flags |= SPACE_FLAG;
		else if (format[*index] == '#')
			flags |= HASH_FLAG;
		else if (format[*index] == '0')
			flags |= ZERO_FLAG;
		else if (format[*index] == '-')
			flags |= MINUS_FLAG;

		(*index)++;
	}

	return (flags);
}
