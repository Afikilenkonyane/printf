#include "main.h"

/**
 * gmt_flags - Calculatsflags
 * @format: Formattedch to print the arguments
 * @j: take a parameter.
 * Return: Fla
 */
int gmt_flags(const char *format, int *j)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int i, curr_j;
	int flag = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j = *j + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (i = 0; FLAG_CH[j] != '\0'; i++)
			if (format[curr_j] == FLAG_CH[i])
			{
				flag |= FLAG_ARR[i];
				break;
			}

		if (FLAG_CH[i] == 0)
			break;
	}

	*i = curr_j - 1;

	return (flag);
}
