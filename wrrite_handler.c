#include "main.h"

/************************* HANDLE write *************************/
/**
 * hand_wrrite_charr - Print string
 * @d: chayes.
 * @buffer: Buffehandle print
 * @flags:  Calculatve flags.
 * @width: get widht.
 * @precision: precisio
 * @size: Size r
 *
 * Return: Number printed.
 */
int hand_wrrite_char(char d, char buffer[],
	int flags, int width, int precision, int size)
{ /* at buffer's right */
	int j = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padding = '0';

	buffer[j++] = d;
	buffer[j] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buffer[BUFF_SIZE - j - 2] = padding;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - j - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - j - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * wrrite_number - Prints string
 * @is_neg: Lis  rguments
 * @index: char.
 * @buffer: Bufferhandle print
 * @flags:  Calculate
 * @width: get widht.
 * @precision: precision
 * @size: Size
 *
 * Return: Numb printed.
 */
int wrrite_number(int is_neg, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1;
	char padding = ' ', ext_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (is_neg)
		ext_ch = '-';
	else if (flags & F_PLUS)
		ext_ch = '+';
	else if (flags & F_SPACE)
		ext_ch = ' ';

	return (wrrite_num(index, buffer, flags, width, precision,
		len, padding, ext_ch));
}
/**
 * wrrite_num - using a bufffer
 * @index: Index
 * @buffer: Buff
 * @flags: Flag
 * @width: widht
 * @prec: Precision
 * @len: length
 * @pad: Pading
 * @ext_c: Extra
 *
 * Return: Number of chars.
 */
int wrrite_num(int index, char buffer[],
	int flags, int width, int prec,
	int len, char pad, char ext_c)

{
	int j, start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = pad = ' ';
	if (prec > 0 && prec < len)
		pad = ' ';
	while (prec > len)
		buffer[--index] = '0', len++;
	if (ext_c != 0)
		len++;
	if (width > len)
	{
		for (j = 1; j < width - len + 1; j++)
			buffer[j] = pad;
		buffer[j] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], j - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (ext_c)
				buffer[--start] = ext_c;
			return (write(1, &buffer[start], j - start) +
				write(1, &buffer[index], len - (1 - start)));
		}
	}
	if (ext_c)
		buffer[--index] = ext_c;
	return (write(1, &buffer[index], len));
}


/**
 * wrrite_unsgnd - unsigned number
 * @is_neg:  negative
 * @index: Index
 * @buffer: buffer
 * @width: witdh
 * @flags: flag
 * @precision: precs
 * @size: Sizer
 *
 * Return: Number chars.
 */
int wrrite_unsgnd(int is_neg, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{

	int len = BUFF_SIZE - index - 1, j = 0;
	char padding = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < len)
		padding = ' ';

	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';

	if (width > len)
	{
		for (j = 0; j < width - len; j++)
			buffer[j] = padding;

		buffer[j] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], j));
		}
		else
		{
			return (write(1, &buffer[0], j) + write(1, &buffer[index], len));
		}
	}

	return (write(1, &buffer[index], len));
}

/**
 * wrrite_pointerr -  address
 * @buffer: Array chars
 * @index: Index at buffer
 * @len: Length
 * @width: Width
 * @flags: Flags
 * @padding: Char
 * @ext_c: Char
 * @padding_start: Index at
 *
 * Return: Number chars.
 */
int wrrite_pointerr(char buffer[], int index, int len,
	int width, int flags, char padding, char ext_c, int padding_start)
{
	int j;

	if (width > len)
	{
		for (j = 3; j < width - len + 3; j++)
			buffer[j] = padding;
		buffer[j] = '\0';
		if (flags & F_MINUS && padding == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], j - 3));
		}
		else if (!(flags & F_MINUS) && padding == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[3], j - 3) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && padding == '0')
		{
			if (ext_c)
				buffer[--padding_start] = ext_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padding_start], j - padding_start) +
				write(1, &buffer[index], len - (1 - padding_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (ext_c)
		buffer[--index] = ext_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

