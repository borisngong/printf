#include "main.h"
/**
  * _printf - prints formated output to the standard output stream
  * @format: pointer to constant character
  * Return: 1 on success and -1 on failure
  */



int _printf(const char *format, ...)
{
	int aggregate;

	conver_t funct_list[] =	{
		{"c", output_character},
		{"s", output_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{NULL, NULL}
	};

	va_list argn;


	if (format == NULL)
		return (-1);

	va_start(argn, format);

	aggregate = format_parser(format, funct_list, argn);
	va_end(argn);

	return (aggregate);
}
