#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define BUFF_SIZE

struct convert
{
	char *cfmt;
	int (*cf)(va_list);
};
typedef struct convert conver_t;


int _printf(const char *format, ...);
int boro_putchr(char c);
int format_parser(const char *format, conver_t funct_list[], va_list argn);
int output_character(va_list);
int output_string(va_list args);
int p_percent(va_list);
int print_unsgined_number(unsigned int n);
int print_number(va_list);
int p_integer(va_list);
#endif




