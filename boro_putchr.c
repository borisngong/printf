#include "main.h"
/**
  * boro_putchr - this writes a single character to the stans output
  * @c: character to be processed
  * Return: int
  */
int boro_putchr(char c)
{
	return (write(1, &c, 1));
}
