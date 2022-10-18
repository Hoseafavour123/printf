#include "main.h"

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
		{'\0', NULL}
	};
	if (format)
		va_start(list, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			while (ids[j].c_id)
			{
				if (format[i] == ids[j].c_id)
				{
					count += ids[j].func_ptr(list);
					break;
				}
				j++;
			}
			if (ids[j].c_id == '\0')
				return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			count += 1;
		}
	}
	va_end(list);
	return (count);
}

