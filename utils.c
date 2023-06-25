#include "main.h"
/**
 * is_printable - this  evaluates if a character is printable
 * @c: Character  to be evaluated.
 * nurudeen
 * Return: 1 , 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code -  This Append ascci in hexadecimal code to buffer
 * @buffer: this is an array of characters.
 * @i: this is the Index at which to start appending.
 * @ascii_code: This is the ASSCI CODE.
 * Return: Always 
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit - this verifies if a character is a digit
 * @c: pointer Char to be evaluated
 * nurudeen
 * Return: 1, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - this is asts a number to the size
 * @num: this are numbers to be casted.
 * @size: thus number indicating the type .
 * adel
 * Return: value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * convert_size_unsgnd -  this Casts a number to the size
 * @num: this shows number to be casted
 * @size: this are number indicating the type to be casted
 * adel
 * Return: num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
