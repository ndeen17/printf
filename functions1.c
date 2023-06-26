#include "main.h"
/**
 * print_unsigned - shows an unsigned int
 * @types: This List all of the arguments
 * @buffer: this is a buffer array to handle the print
 * @flags:  it calculates the active flags
 * @width: this gets the width
 * @precision: this gets the specification
 * @size: this is a size specifier
 * Return: it returns the number of characters printed
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/*written by nurudeen*/
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

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
 * print_octal - show unsigned number in octal notation
 * @types: This List all of the arguments
 * @buffer: this is a buffer array to handle the print
 * @flags:  it calculates the active flags
 * @width: this gets the width
 * @precision: this gets the specification
 * @size: this is a size specifier
 * Return: it returns the number of characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
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
 * print_hexadecimal - Shows an unsigned number in hexadecimal notation
 * @types: This List all of the arguments
 * @buffer: this is a buffer array to handle the print
 * @flags:  it calculates the active flags
 * @width: this gets the width
 * @precision: this gets the specification
 * @size: this is a size specifier
 * Return: it returns the number of characters printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Shows an unsigned hexadadecimal noation
 * @types: This List all of the arguments
 * @buffer: this is a buffer array to handle the print
 * @flags:  it calculates the active flags
 * @width: this gets the width
 * @precision: this gets the specification
 * @size: this is a size specifier
 * Return: it returns the number of characters printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - shows a hexadecimal number in lower or upper
 * @types: This List all of the arguments
 * @buffer: this is a buffer array to handle the print
 * @flags:  it calculates the active flags
 * @width: this gets the width
 * @precision: this gets the specification
 * @size: this is a size specifier
 * Return: it returns the number of characters printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

