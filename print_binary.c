#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned int
 * @n: The number to convert and print
 *
 * Return: The number of characters printed
 */
int print_binary(unsigned int n)
{
	int count = 0;
	int started = 0;
	unsigned int mask = 1 << 31; /* Start with the highest bit */

	while (mask)
	{
		if (n & mask)
		{
			started = 1;
			count += write(1, "1", 1);
		}
		else if (started)
		{
			count += write(1, "0", 1);
		}
		mask >>= 1;
	}

	if (!count) /* If number is 0 */
		count += write(1, "0", 1);

	return (count);
}
