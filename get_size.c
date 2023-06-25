#include "main.h"

/**
 * get_size - this calculates the argument
 * @format: The formatted string arguments
 * @i: the List of arguments to be printed.
 * Adel
 * Return: the precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

