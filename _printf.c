#include "main.h"
#include <stdio.h>

/**
 * _printf - writes strings to stdout
 * @format: format of characters
 * @...: variable arguments
 *
 * Return: number of characters
 */

int _printf(const char *format, ...)
{
	int i, j = 0, count = 0;
	va_list list;

	specifier_t ids[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_mod},
		{'i', print_int},
		{'d', print_int},
		{'\0', NULL}
	};
	va_start(list, format);
	for (i = 0; format[i]; i++)
		if (format[i] == '%')
		{
			i++;
			for (; format[i] != '\0'; i++)
			{
				for (j = 0; ids[j].c_id != '\0'; j++)
					if (format[i] == ids[j].c_id)
					{
						count += ids[j].func_ptr(list);
						break;


					}
				if (ids[j].c_id)
					break;
			}
			if (format[i] == '\0')
				return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			count += 1;
		}


	va_end(list);
	return (count);
}
