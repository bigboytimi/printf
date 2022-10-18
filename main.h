#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *str);
int print_char(va_list ap);
int print_str(va_list ap);
int print_nbr(va_list ap);
int print_binary(va_list ap);
int print_hexa_lower(va_list ap);
int print_octal(va_list ap);
int print_hexa_upper(va_list ap);
int print_unsigned(va_list ap);
int print_str_unprintable(va_list ap);
int print_str_reverse(va_list ap);
int print_ptr(va_list ap);
int print_rot13(va_list ap);
int print_percent(va_list ap __attribute__((unused)));
int print_number(int n);
int print_unsigned_number(unsigned int n);
int _puts(char *str, int ascii);
int _nbr_len(int prmNumber);
int _strlen_recursion(char *s);
int convert_alpha_numeric(int nb, int upper);
char *convert_rot13(char *str);
char *convert_base(unsigned long nb, unsigned int base, int upper);
char *_strdup(char *str);
char *convert_base_pointer(unsigned long p);

/**
 * struct flags_printf - struct conversion to function
 * @c: flag string
 * @f: pointer to func
 */

typedef struct flags_printf
{
	char *c;
	int (*f)(va_list);
} flags_p;


/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);


#endif
