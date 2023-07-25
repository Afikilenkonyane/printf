#include "main.h"

/**
 * gmt_width - width for printing
 * @format: Formattets.
 * @j: e printed.
 * @args: lguments.
 *
 * Return: width.
 */
int gmt_width(const char *format, int *j, va_list args)
{
	int curr_j;
	int wid = 0;

	for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
	{
		if (is_digi(format[curr_j]))
		{
			wid *= 10;
			wid += format[curr_j] - '0';
		}
		else if (format[curr_j] == '*')
		{
			curr_j++;
			wid = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*j = curr_j - 1;

	return (wid);
}

