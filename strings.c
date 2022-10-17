#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - write all char from string to stdout
 * @str: string to print
 * @ascii: enable ascii restriction
 * Return: number of printed char
 */

int _puts(char *str, int ascii)
{
	char *s;
	int i = 0, sum = 0;

	while (str[i])
	{
		if (((str[i] >= 0 && str[i] < 32) || str[i] >= 127) && ascii)
		{
			s = convert_base(str[i], 16, 1);
			sum += write(1, "\\x", 2);
			if (str[i] >= 0 && str[i] < 16)
				sum += _putchar('0');
			sum += _puts(s, 0);
			free(s);
			i++;
		}
		else
		{
			sum += _putchar(str[i]);
			i++;
		}
	}
	return (sum);
}
