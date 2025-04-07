#include "main.h"

/**
 * convert_base - Converts an unsigned int to a given base and prints it
 * @n: The number
 * @base: The base to convert to (e.g. 8, 10, 16)
 * @uppercase: If true, use A–F for hex; else a–f
 * @hash_flag: Add prefix like 0x or 0X or 0 for octal if true
 * Return: Number of characters printed
 */
int convert_base(unsigned int n, int base, int uppercase, int hash_flag)
{
	char buffer[50];
	char *digits;
	int i = 0, count = 0;

	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0)
		return (write(1, "0", 1));
	if (hash_flag)
	{
		if (base == 8)
			count += write(1, "0", 1);
		else if (base == 16 && uppercase)
			count += write(1, "0X", 2);
		else if (base == 16 && !uppercase)
			count += write(1, "0x", 2);
	}

	while (n)
	{
		buffer[i++] = digits[n % base];
		n /= base;
	}

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
