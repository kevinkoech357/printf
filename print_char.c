#include "main.h"

/**
* print_char - prints a char
* @list: list a of arguments
* @buffer: buffer array to handle print
* @flags:  calculates active flags
* @width: width
* @precision: precision specification
* @size: size specifier
* Return: number of chars printed
*/

int print_char(va_list list, char buffer[],
int flags, int width, int precision, int size)
{
	char c = va_arg(list, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}

