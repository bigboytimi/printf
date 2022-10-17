#include <stdarg.h>
#include "main.h"
#include <stddef.h>

/**
 * get_func - get the function to convert char
 * @c: character
 * Return: pointer to function
 */

int (*get_func(const char c))(va_list)
{
	int i = 0;

	flags_p fp[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_nbr},
		{"d", print_nbr},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"u", print_unsigned},
		{"S", print_str_unprintable},
		{"r", print_str_reverse},
		{"p", print_ptr},
		{"R", print_rot13},
		{"%", print_percent}
	};

	while (i < 14)
	{
		if (c == fp[i].c[0])
		{
			return (fp[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * _printf - produce output according to format
 *
 * @format: format string
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int len = 0, i = 0;

	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = get_func(format[i + 1]);
			if (func == NULL)
			{
				_putchar(format[i]);
				len++;
				i++;
			}
			else
			{
				len += func(ap);
				i += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(ap);
	return (len);
}
