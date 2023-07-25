#include "main.h"

/**
 * is_prrintable - is printable
 * @d: Char.
 *
 * Return: 0
 */
int is_prrintable(char d)
{
	if (d >= 32 && d < 127)
		return (1);

	return (0);
}

/**
 * app_hexa_code - buffer
 * @buffer: Array of chars.
 * @j: Index
 * @asci_code: ASI CODE.
 * Return:  3
 */
int app_hexa_code(char asci_code, char buffer[], int j)
{
	char mapp_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (asci_code < 0)
		asci_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = mapp_to[asci_code / 16];
	buffer[j] = mapp_to[asci_code % 16];

	return (3);
}

/**
 * is_digi -  a digit
 * @d: evaluated
 *
 * Return: 0
 */
int is_digi(char d)
{
	if (d >= '0' && d <= '9')
		return (1);

	return (0);
}

/**
 * conv_size_number - specified size
 * @numb: Number  casted.
 * @siz: Numbertype to be casted.
 *
 * Return: Castedm
 */
long int conv_size_number(long int numb, int siz)
{
	if (siz == M_LONG)
		return (numb);
	else if (siz == M_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * conv_size_unsgnd - Casts fied size
 * @numb: Number e casted
 * @siz: Numbe to be casted
 *
 * Return: Casted f num
 */
long int conv_size_unsgnd(unsigned long int numb, int siz)
{
	if (siz == M_LONG)
		return (numb);
	else if (siz == M_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}

