#include "main.h"

 /**
 * print_unsigned - prints an unsigned number
 * @list: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed.
 */

int print_unsigned(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - prints an unsigned number in octal notation
 * @list: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_octal(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prints an unsigned number in hexadecimal notation
 * @list: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: size specifier
 * Return: number of chars printed
 */
int print_hexadecimal(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(list, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal notation
 * @list: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */
int print_hexa_upper(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(list, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

