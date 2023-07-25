#include "main.h"

/**
 * gmt_flags - Calculatsflags
 * @format: Formattedch to print the arguments
 * @j: take a parameter.
 * Return: Fla
 */
int gmt_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, cur_i;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (j = 0; FLAG_CH[j] != '\0'; j++)
			if (format[cur_i] == FLAG_CH[j])
			{
				flag |= FLAG_ARR[j];
				break;
			}

		if (FLAG_CH[j] == 0)
			break;
	}

	*i = cur_i - 1;

	return (flag);
}
