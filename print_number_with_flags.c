#include "main.h"

/**
 * print_number_with_flags - Print number with '+' or ' ' if needed
 * @args: va_list containing the number
 * @plus: flag for '+'
 * @space: flag for ' '
 *
 * Return: number of characters printed
 */
int print_number_with_flags(va_list args, int plus, int space)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n >= 0)
	{
		if (plus)
			count += write(1, "+", 1);
		else if (space)
			count += write(1, " ", 1);
	}

	count += print_number_int(n);
	return (count);
}
