#include "main.h"

/**
  * print_number - to print a single integer  takes va_list
  * argument and returns and int
  * @argn: handle and hold variable argument passed to function
  * Return: an integer value stored in the len
  */
int print_number(va_list argn)
{
	int k;
	int divisor;
	unsigned int absolute_val;
	int len;

	k = va_arg(argn, int);
	divisor = 1;
	len = 0;

	if (k < 0)
	{
		len += boro_putchr('-');
		absolute_val = k * -1;
	}
	else
	{
		absolute_val = k;
	}

	for (; absolute_val / divisor > 9; )
		divisor *= 10;

	for (; divisor != 0; )
	{
		len += boro_putchr('0' + absolute_val / divisor);
		absolute_val %= divisor;
		divisor /= 10;
	}
	return (len);
}

/**
  * print_unsigned_number - outputs the unsigned int of a number
  * @k: int to check
  * Return: len (number of digts in the unsigned numbers)
  */
int print_unsigned_number(unsigned int k)
{
	int divisor;
	int len;
	unsigned int absolute_val;

	divisor = 1;
	len = 0;

	absolute_val = k;

	for (; absolute_val / divisor > 9; )
		divisor *= 10;

	for (; divisor != 0; )
	{
		len += boro_putchr('0' + absolute_val / divisor);
		absolute_val %= divisor;
		divisor /= 10;
	}
	return (len);
}

/**
  * output_character - to print a single character to standard ouput
  * @argn: hold and handle arguments passed to the function
  * Return: characters
  */
int output_character(va_list argn)
{
	char s_count;

	s_count = va_arg(argn, int);
	boro_putchr(s_count);
	return (1);
}

/**
  * output_string - prints string to stdout
  * @argn: list of variable arguments
  * Return: final length of string
  */
int output_string(va_list argn)
{
	int j;
	const char *str;

	str = va_arg(argn, const char*);
	if (str == NULL)
		str = "(null)";
	for (j = 0; str[j] != '\0'; j++)
		boro_putchr(str[j]);
	return (j);
}

/**
  * p_percent - output  percen and print integer
  * @argn: variable list of arguments
  * Return: 1 on success
  */
int p_percent(__attribute__((unused)) va_list argn)
{
	boro_putchr('%');
	return (1);
}

/**
  * p_integer - a function that print integer
  * @argn: variable list of arguments
  * Return: int on succes
  */
int p_integer(va_list argn)
{
	int k;

	k = print_number(argn);
	return (k);
}
