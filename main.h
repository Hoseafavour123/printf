#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
  * struct specifiers - A structure of format specifiers
  * with a pointer to a function that performs the conversion
  * @c: character specifier
  * @func_ptr - function pointer that takes variable arguments
  * @...: variable arguments
  * @c_id: character format
  * @func_ptr: Function pointer
  */

typedef struct specifiers
{
	char c_id;
	int (*func_ptr)(va_list);
} specifier_t;

int _printf(const char *format, ...);
int print_char(va_list list);
int print_string(va_list list);
int print_mod(va_list list);

#endif
