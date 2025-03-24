#include <stdio.h>
#include "main.h"

/**
 * main - Entry point for testing _printf.
 *
 * Return: Always 0.
 */
int main(void)
{
    int len1, len2;

    /* Test character specifier */
    len1 = _printf("Character: [%c]\n", 'H');
    len2 = printf("Character: [%c]\n", 'H');
    printf("Lengths: _printf: %d, printf: %d\n", len1, len2);

    /* Test string specifier */
    len1 = _printf("String: [%s]\n", "Hello, World!");
    len2 = printf("String: [%s]\n", "Hello, World!");
    printf("Lengths: _printf: %d, printf: %d\n", len1, len2);

    /* Test percent specifier */
    len1 = _printf("Percent: [%%]\n");
    len2 = printf("Percent: [%%]\n");
    printf("Lengths: _printf: %d, printf: %d\n", len1, len2);

    return (0);
}
