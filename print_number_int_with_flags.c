#include "main.h"

/**
 * print_number_int_with_flags - print integer with + or space if needed
 * @n: number
 * @plus: + flag
 * @space: space flag
 * Return: number of characters printed
 */
int print_number_int_with_flags(int n, int plus, int space)
{
    int count = 0;
    char digits[] = "0123456789";

    if (n < 0)
    {
        count += write(1, "-", 1);
        n = -n;
    }
    else
    {
        if (plus)
            count += write(1, "+", 1);
        else if (space)
            count += write(1, " ", 1);
    }

    if (n / 10)
        count += print_number_int(n / 10);

    count += write(1, &digits[n % 10], 1);
    return (count);
}
