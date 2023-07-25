#include "main.h"

void prrint_buff(char buffer[], int *buff_index);

/**
 * _printf - custom Printf function
 * @format: formatted char.
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{
	int j, print = 0, print_char = 0;
	int flags, width;
	int precs, size, buff_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_index++] = format[j];
			if (buff_index == BUFF_SIZE)
				prrint_buff(buffer, &buff_index);
			print_char++;
		}
		else
		{
			prrint_buff(buffer, &buff_index);
			flags = gmt_flags(format, &j);
			width = gmt_width(format, &j, args);
			precs = gmt_precision(format, &j, args);
			size = gmt_size(format, &j);
			++j;
			print = handle_prrint(format, &j, args, buffer,
				flags, width, precs, size);
			if (print == -1)
				return (-1);
			print_char += print;
		}
	}

	prrint_buff(buffer, &buff_index);

	va_end(args);

	return (print_char);
}

/**
 * prrint_buff - Prints the existing buffer
 * @buffer: array of char
 * @buff_index: index represents the length.
 */
void prrint_buff(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}

