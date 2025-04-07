#include "main.h"

/**
 * print_pointer - Prints pointer address
 * @ptr: Pointer to print
 * Return: Number of characters printed
 */
int print_pointer(void *ptr)
{
	unsigned long addr = (unsigned long)ptr;
	char buffer[20];
	char *hex = "0123456789abcdef";
	int i = 0, count = 0;

	if (!ptr)
		return (write(1, "(nil)", 5));

	count += write(1, "0x", 2);

	while (addr)
	{
		buffer[i++] = hex[addr % 16];
		addr /= 16;
	}
	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
