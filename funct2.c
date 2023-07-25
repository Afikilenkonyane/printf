#include "main.h"

/******************  POINTER ******************/
/**
 * prrint_pointer - pointer variable
 * @args: argument
 * @buffer: Buffer  print
 * @flags:  flags
 * @width: width
 * @precision: Precisin
 * @size: size
 * Return: no printed
 */
int prrint_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char ext_c = 0, pad = ' ';
	int index = BUFF_SIZE - 2, len = 2, start = 1;
	unsigned long num_ad;
	char mapp_to[] = "0123456789abcdef";
	void *ad = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (ad == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_ad = (unsigned long)ad;

	while (num_ad > 0)
	{
		buffer[index--] = mapp_to[num_ad % 16];
		num_ad /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		ext_c = '+', len++;
	else if (flags & F_SPACE)
		ext_c = ' ', len++;

	index++;

	return (wrrite_pointerr(buffer, index, len,
		width, flags, pad, ext_c, start));
}

/************************* NON PRINTABLE *************************/
/**
 * prrint_non_printable -  non printable chars
 * @args: arguments
 * @buffer: to handle print
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of printed
 */
int prrint_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, toff = 0;
	char *spt = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (spt == NULL)
		return (write(1, "(null)", 6));

	while (spt[j] != '\0')
	{
		if (is_printable(spt[j]))
			buffer[j + toff] = spt[j];
		else
			toff += append_hexa_code(spt[j], buffer, j + toff);

		j++;
	}

	buffer[j + toff] = '\0';

	return (write(1, buffer, j + toff));
}

/************************* REVERSE *************************/
/**
 * prrint_rreverse - reverse string.
 * @args: arguments
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Numbers of printed
 */

int prrint_rreverse(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char *spt;
	int j, con = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	spt = va_arg(args, char *);

	if (spt == NULL)
	{
		UNUSED(precision);

		spt = ")Null(";
	}
	for (j = 0; spt[j]; j++)
		;

	for (j = j - 1; j >= 0; j--)
	{
		char y = spt[j];

		write(1, &y, 1);
		con++;
	}
	return (con);
}
/************************* ROT13 *************************/
/**
 * prrint_ro13tring - Print a string in rot13.
 * @args: arguments
 * @buffer: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Numbers printed
 */
int prrint_ro13tring(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char z;
	char *spt;
	unsigned int j, i;
	int con = 0;
	char ni[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char tou[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	spt = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (spt == NULL)
		spt = "(AHYY)";
	for (j = 0; spt[j]; j++)
	{
		for (i = 0; ni[i]; i++)
		{
			if (ni[i] == spt[j])
			{
				z = tou[i];
				write(1, &z, 1);
				con++;
				break;
			}
		}
		if (!ni[i])
		{
			z = spt[j];
			write(1, &z, 1);
			con++;
		}
	}
	return (con);
}

