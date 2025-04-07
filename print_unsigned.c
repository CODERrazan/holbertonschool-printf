#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @n: The unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int n)
{
	int count = 0;
	unsigned int div = 1;
	unsigned int temp = n;

	/* Find highest divisor */
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	/* Print digit by digit */
	while (div)
	{
		char digit = '0' + n / div;
		count += write(1, &digit, 1);
		n %= div;
		div /= 10;
	}

	return (count);
}
