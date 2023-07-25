#include "main.h"

/**
 * gmt_precision - precision for printing
 * @format: Formatteds
 * @j: List of arguments to be printed.
 * @args: list of arguments.
 *
 * Return: Precision.
 */
int gmt_precision(const char *format, int *j, va_list args)
{
	int cur_d = *j + 1;
	int precision = -1;

	if (format[cur_d] != '.')
		return (precision);

	precision = 0;

	for (cur_d += 1; format[cur_d] != '\0'; cur_d++)
	{
		if (is_digi(format[cur_d]))
		{
			precision *= 10;
			precision += format[cur_d] - '0';
		}
		else if (format[cur_d] == '*')
		{
			cur_d++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*j = cur_d - 1;

	return (precision);
}

