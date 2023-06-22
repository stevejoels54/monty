#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 * @str: string to check
 *
 * Return: 1 if string is a digit, 0 otherwise
 */

int is_digit(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
