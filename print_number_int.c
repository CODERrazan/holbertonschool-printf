#include "main.h"

/**
 * print_number_int - prints an integer to stdout
 * @n: number to print
 * Return: number of characters printed
 */
int print_number_int(int n)
{
    int count = 0;
    char digits[] = "0123456789";

    if (n < 0)
    {
        count += write(1, "-", 1);
        n = -n;
    }

    if (n / 10)
        count += print_number_int(n / 10);

    count += write(1, &digits[n % 10], 1);
    return (count);
}
