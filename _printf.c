#include "main.h"

/* function declaration */

void print_buffer(char buffer[], int *buff_index);

/**
* _printf - function definition
*
* @format: specifier string
*
* Return: printed characters
*
*/

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;

	va_list list;

	char buffer[BUFF_SIZE];

	if (format == NULL)
			return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = _precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_index);

	va_end(list);

	return (printed_chars);
}

/**
* print_buffer - prints the content of the buffer
* @buffer: array of chars
* @buff_index: index at which to add next char
* Return: void
*/

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
	{
		write(1, &buffer[0], *buff_index);
	}

	*buff_index = 0;
}

