#include "main.h"

/**
 * print_custom_string - Prints string with non-printables as \xXX
 * @str: The input string
 *
 * Return: Number of characters printed
 */
int print_custom_string(char *str)
{
	int count = 0;
	char hex[3];
	int i;

	if (!str)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += write(1, "\\x", 2);

			hex[0] = "0123456789ABCDEF"[(str[i] >> 4) & 0xF];
			hex[1] = "0123456789ABCDEF"[str[i] & 0xF];
			hex[2] = '\0';

			count += write(1, hex, 2);
		}
		else
		{
			count += write(1, &str[i], 1);
		}
	}
	return (count);
}
