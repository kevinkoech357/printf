#include "main.h"

/**
* print_char - prints a char
* @list: list of arguments
* @buffer: buffer array to handle print
* Return: number of chars printed
*/

int print_char(va_list types, char buffer[],)
{
	char c = va_arg(list, int);

	return (handle_write_char(c, buffer, size));
}
