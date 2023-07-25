#include "main.h"

/************************* PRINT UNSGND NUMBER *************************/
/**
 * prrint_unsigned - Print unsigned number
 * @args: List arguments
 * @buffer: Bufferto print
 * @flags:  Calculate flags
 * @width: get widht
 * @precision: Precision specifier
 * @size: Size specification
 * Return: No of printed.
 */
int prrint_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(args, unsigned long int);

	numb = conv_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[j--] = (numb % 10) + '0';
		numb /= 10;
	}

	j++;

	return (wrrite_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************* PRINT IN OCTAL  ****************/
/**
 * prrint_octal - Print in octal notation
 * @args: List arguments
 * @buffer: Bufferto print
 * @flags:  Calculate flags
 * @width: get widtht
 * @precision: Precision specifier
 * @size: Size specification
 * Return: Number of printed
 */
int prrint_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(args, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = conv_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[j--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && init_numb != 0)
		buffer[j--] = '0';

	j++;

	return (wrrite_unsgnd(0, j, buffer, flags, width, precision, size));
}

/************** PRINT IN HEXADECIMAL **************/
/**
 * prrint_hexadecimal - Prints  hexadecimal notation
 * @args: List arguments
 * @buffer: Buffer to  print
 * @flags:  Calculates flags
 * @width: get widht
 * @precision: Precision specifier
 * @size: Size specification
 * Return: No of  printed
 */
int prrint_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (prrint_hexa(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT IN UPPER HEXADECIMAL **************/
/**
 * prrint_hexa_upper - Prints  upper hexadecimal notation
 * @args: List
 * @buffer: Bufferto print
 * @flags:  Calculate flags
 * @width: get widht
 * @precision: Precision specifuer
 * @size: Size specifiecation
 * Return: Number of printed
 */
int prrint_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (prrint_hexa(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEX LOWER OR UPPER **************/
/**
 * prrint_hexa - lower or upper
 * @args: Lis arguments
 * @mapp_to: Array map the number to
 * @buffer: Buffer print
 * @flags:  Calculate flags
 * @flag_ch: Calculater active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifcation
 * @size: Size specifier
 * Return: No printed
 */
int prrint_hexa(va_list args, char mapp_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_numb = num;

	UNUSED(width);

	num = conv_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = mapp_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_numb != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (wrrite_unsgnd(0, j, buffer, flags, width, precision, size));
}

