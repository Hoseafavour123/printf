#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
  * _printf - returns the number of characters passed to it and prints
  * the strings to console
  * @format: format specifier
  *
  * Return: number of characters passed to it
  */

int _printf(const char *format, ...)
{
	int i = 0, str_len = 0, total = 0;
	char *str;
	va_list ptr;

	if (format != NULL)
		va_start(ptr, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			write(1, va_arg(ptr,int), 1);
			total += 1;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(ptr, char*);
			str_len = strlen(str);
			write(1, str, str_len);
			total += 1;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, '%', 1);
			total += 1;
		}
		else
		{
			write(1, (int)format[i], 1);
			total += 1;
		}
		i++;
	}

	return (total);
}

