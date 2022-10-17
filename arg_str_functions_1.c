#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_percent - print percent character
 * @args: char
 * Return: print percent char
 */

int print_percent(va_list args __attribute__((unused)))
{
	return (_putchar('%'));
}
