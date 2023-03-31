#include "main.h"

/**
* print_percent - prints a percent sign
* @list: list of arguments
* @buffer: buffer array to handle print
* Return: int value
*/

int print_percent(va_list list, char buffer[],
int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(list);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}
