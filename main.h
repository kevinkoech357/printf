#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**FLAGS**/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**SIZES**/


int _printf(const char *format, ...);
int _precision(const char *format, int *i, va_list list);
int print_int(va_list list, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list list, char buffer[], int flags, int width, int precision, int size);
int print_char(va_list list, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list list, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list list, char buffer[]);

#endif /* MAIN_H */