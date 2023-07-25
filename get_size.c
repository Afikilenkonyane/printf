#include "main.h"

/**
 * gmt_size - size to argument
 * @format: Formatted  the arguments
 * @j: arguments to be printed.
 *
 * Return: Precsn.
 */
int gmt_size(const char *format, int *j)
{
	int curr_j = *j + 1;
	int s = 0;

	if (format[curr_j] == 'l')
		s = M_LONG;
	else if (format[curr_j] == 'h')
		s = M_SHORT;

	if (s == 0)
		*j = curr_j - 1;
	else
		*j = curr_j;

	return (s);
}

