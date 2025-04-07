#include "main.h"

/**
 * print_number_with_flags - Handles + and space flags for integers
 * @args: va_list
 * @plus: flag +
 * @space: flag space
 * Return: number of characters printed
 */
int print_number_with_flags(va_list args, int plus, int space)
{
    int n = va_arg(args, int);
    return (print_number_int_with_flags(n, plus, space));
}
