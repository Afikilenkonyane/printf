#include "main.h"
/**
 * handle_prrint - Print on its type
 * @fomt: Formatted arguments.
 * @args: List arguments.
 * @index: index.
 * @buffer: Bufferandle print.
 * @flags: Calculatsflags
 * @width: get widht.
 * @precision: Precision specificier
 * @size: Size specification
 * Return: 1 or 2;
 */
int handle_prrint(const char *fomt, int *index, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int j, unk_len = 0, printed_char = -1;
	fomt_t fomt_args[] = {
		{'c', prrint_charr}, {'s', prrint_strring}, {'%', prrint_perrcent},
		{'i', prrint_int}, {'d', prrint_int}, {'b', prrint_binary},
		{'u', prrint_unsigned}, {'o', prrint_octal}, {'x', prrint_hexadecimal},
		{'X', prrint_hexa_upper}, {'p', prrint_pointer}, {'S', prrint_non_printable},
		{'r', prrint_reverse}, {'R', prrint_ro13tring}, {'\0', NULL}
	};
	for (j = 0; fomt_args[j].fomt != '\0'; j++)
		if (fomt[*index] == fomt_args[j].fomt)
			return (fomt_args[j].fn(args, buffer, flags, width, precision, size));

	if (fomt_types[i].fomt == '\0')
	{
		if (fomt[*index] == '\0')
			return (-1);
		unk_len += write(1, "%%", 1);
		if (fomt[*index - 1] == ' ')
			unk_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fomt[*index] != ' ' && fomt[*index] != '%')
				--(*index);
			if (fomt[*index] == ' ')
				--(*index);
			return (1);
		}
		unk_len += write(1, &fomt[*index], 1);
		return (unk_len);
	}
	return (printed_char);
}

