#include "main.h"

/**
 * convert_base - Converts an unsigned int to a given base and prints it
 * @n: The number
 * @base: The base to convert to (e.g. 8, 10, 16)
 * @uppercase: If true, use A-F for hex; else a-f
 * Return: Number of characters printed
 */
int convert_base(unsigned int n, int base, int uppercase)
{
	char buffer[50];
	char *digits;
	int i = 0, count = 0;

	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0)
		return (write(1, "0", 1));

	while (n)
	{
		buffer[i++] = digits[n % base];
		n /= base;
	}

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
