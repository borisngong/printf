#include "main.h"
/**
  * format_parser - a function responsible for parsing a format string and
  * processing its format specifiers
  * @format: pointer to constant characterand hold the input format string
  * @funct_list: contains information for specific conversion function
  * @argn: argument passed to the parser function
  * Return: aggregate on succes and -1 on failure
  */
int format_parser(const char *format, conver_t funct_list[], va_list argn)
{
	int k = 0, l, conversion_result, aggregate = 0;

	while (format[k] != '\0')
	{
		if (format[k] == '%')
		{l = 0;
			while (funct_list[l].cf != NULL)
			{
				if (format[k + 1] == funct_list[l].cfmt[0])
				{conversion_result = funct_list[l].cf(argn);
					if (conversion_result == -1)
						return (-1);
					aggregate += conversion_result;
					break;
				}
				l++;
			}
			if (funct_list[l].cfmt == NULL && format[k + 1] != ' ')
			{
				if (format[k + 1] != '\0')
				{
					boro_putchr(format[k]);
					boro_putchr(format[k + 1]);
					aggregate += 2;
				}
				else
				{
					return (-1);
				}
			}
			k = k + 1;
		}
		else
		{
			boro_putchr(format[k]);
			aggregate++;
		}
		k++;
	}
	return (aggregate);
}
