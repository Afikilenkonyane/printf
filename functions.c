#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - prints char
 * @args: List of arguments
 * @buffer: Buffer array to print
 * @flags:  Calculat flags active
 * @width: Widht
 * @precision: Precs specificier
 * @size: Size specifier
 *
 * Return: Number of charprinted
 */
int prrint_charr(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char p = va_arg(args, int);

	return (hand_wrrite_char(p, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * prrint_strring - Prints string
 * @args: List arguments
 * @buffer: Buffer to print
 * @flags:  Calculates flags active
 * @width: get widht.
 * @precision: Precision specifier
 * @size: Size specifiation
 * Return: Number char that whereprinted
 */
int prrint_strring(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, j;
	char *spt = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (spt == NULL)
	{
		spt = "(null)";
		if (precision >= 6)
			spt = "      ";
	}

	while (spt[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &spt[0], len);
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &spt[0], len);
			return (width);
		}
	}

	return (write(1, spt, len));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * prrint_perrcent - Prints percent
 * @args: List arguments
 * @buffer: Bufferto print
 * @flags:  Calculate flags
 * @width: get widht.
 * @precision: Precision specifier
 * @size: Size specificaion
 * Return: No. of chars printed
 */
int prrint_perrcent(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * prrint_int - Printed int
 * @args: List arguments
 * @buffer: Buffer to  print
 * @flags:  Calculates flags
 * @width: get widht.
 * @precision: Precision specifier
 * @size: Size specification
 * Return: No of chars printed
 */
int prrint_int(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int index = 0;
	long int p = va_arg(args, long int);
	unsigned long int numb;

	p = conv_size_number(p, size);

	if (p == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)p;

	if (p < 0)
	{
		numb = (unsigned long int)((-1) * p);
		index = 1;
	}

	while (numb > 0)
	{
		buffer[j--] = (numb % 10) + '0';
		numb /= 10;
	}

	j++;

	return (wrrite_number(index, j, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * prrint_binary - Prints unsined number
 * @args: List arguments
 * @buffer: Buffer print
 * @flags:  Calculate flags
 * @width: get widht.
 * @precision: Precision specificier
 * @size: Size specification
 * Return: Numbers of printed.
 */
int prrint_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int q, w, j, summ;
	unsigned int b[32];
	int con;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	q = va_arg(args, unsigned int);
	w = 2147483648; /* (2 ^ 31) */
	b[0] = q / w;
	for (j = 1; j < 32; j++)
	{
		w /= 2;
		b[j] = (q / w) % 2;
	}
	for (j = 0, summ = 0, con = 0; j < 32; j++)
	{
		summ += b[j];
		if (summ || j == 31)
		{
			char y = '0' + b[j];

			write(1, &y, 1);
			con++;
		}
	}
	return (con);
}

