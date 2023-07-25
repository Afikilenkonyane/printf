#include "main.h"

void print_buff(char buffer[], int *buff_ind);

/**
 * _printf - Replica of printf function
 * @format: char to format
 *
 * Return: the no. of chars printed.
 */
int _printf(const char *format, ...);
{
	int j, print = 0, print_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list rest;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(rest, format);
	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buffind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buff(buffer, &buff_ind);
			print_char++;
		}

		else
		{
			print_buff(buffer, &buff_ind);
			flags = for_flags(format, &j);
			width = for_width(format, &j, rest);
			prcision = for_precision(format, &j, rest);
			size = for_size(format, &j);
			if (print == -1)
				return (-1);
			print_char += print;
		}

	}
	print_buff(buffer, *buff_ind);

	va_end(rest);

	return (print_char);
}

/**
 * print_buff - Prints content of existing buffer
 * @buffer: Array of chars
 * @buff_ind: index at which to add next char
 */
void print_buff(char buffer[], int *bufff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
