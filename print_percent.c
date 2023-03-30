#include "main.h"

/**
* print_percent - prints a percent sign
* @list: list of arguments
* @buffer: buffer array to handle print
* Return: int value
*/

int print_percent(va_list list, char buffer[])
{
	UNUSED(buffer);

	return (write(1, "%%", 1));
}
