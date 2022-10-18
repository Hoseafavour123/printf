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

	void(list);

	write(1, &c, 1);

	return (1);
}

