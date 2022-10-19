#include "main.h"

/**
 * print_char - prints a character from variable arguments
 * to the screen
 * @list: variable arguments
 *
 * Return: number of character printed
 */

int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);

	write(1, &c, 1);

	return (1);
}

/**
 * print_string - prints a string from variable arguments
 * to stdout
 * @list: variable arg
 *
 * Return: number of characters of strings
 */

int print_string(va_list list)
{
	int i = 0, count = 0;
	char *str_buffer;

	str_buffer = va_arg(list, char *);

	if (str_buffer == NULL)
		str_buffer = "(null)";

	for (i = 0; str_buffer[i]; i++)
	{
		write(1, &str_buffer[i], 1);
		count += 1;
	}

	return (count);
}

/**
 * print_mod - prints the '%' character to stdout
 * @list: variable args
 *
 * Return: number of characters
 */

int print_mod(va_list list)
{
	char c = '%';

	(void)list;

	write(1, &c, 1);

	return (1);
}

/**
 * _print_int - prints a decimal integer
 * @ls: list of arguments, va_list
 *
 * Return: the number of printed chars, int
 */
int print_int(va_list list)
{
	int a, expo = 1, len = 0;
	unsigned int n;
	char pr;
        
	a = va_arg(list, int);
	if (a < 0)
	{
		pr = '-';
		len = len + write(1, &pr, 1);
		n = a * -1;
	}
	else
		n = a;
	while (n / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + write(1, &pr, 1);
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}

