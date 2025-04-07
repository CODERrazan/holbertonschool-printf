#include "main.h"
/**
* print_char - Prints a single character.
* @args: The argument list containing the character.
*
* Return: Number of characters printed.
*/
int print_char(va_list args)
{
char c = va_arg(args, int);
return (write(1, &c, 1));
}
/**
* print_string - Prints a string.
* @args: The argument list containing the string.
*
* Return: Number of characters printed.
*/
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int count = 0;

if (!str)
str = "(null)";

while (*str)
count += write(1, str++, 1);

return (count);
}
/**
* print_percent - Prints a literal percent sign.
*
* Return: Number of characters printed.
*/
int print_percent(void)
{
return (write(1, "%", 1));
}
/**
* print_number_recursive - Recursively prints the digits of a number.
* @n: The unsigned number to print.
*
* Return: Number of characters printed.
*/
int print_number_recursive(unsigned int n)
{
int count = 0;

if (n / 10)
count += print_number_recursive(n / 10);

count += write(1, &"0123456789"[n % 10], 1);

return (count);
}

/**
* print_number - Prints an integer.
* @args: The argument list containing the integer.
*
* Return: Number of characters printed.
*/
int print_number(va_list args)
{
int n = va_arg(args, int);
unsigned int num;
int count = 0;

if (n < 0)
{
count += write(1, "-", 1);
num = -n;
}
else
{
num = n;
}

count += print_number_recursive(num);
return (count);
}

/**
* _printf - Produces output according to a format.
* @format: A character string containing directives.
*
* Return: Number of characters printed (excluding null byte),
*         or -1 if an error occurs.
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
if (!format)
return (-1);
va_start(args, format);
while (*format)
{
if (*format == '%') /* Format specifier detected */
{
format++;
if (!*format)
return (-1);
if (*format == 'c')
count += print_char(args);
else if (*format == 's')
count += print_string(args);
else if (*format == '%')
count += print_percent();
else if (*format == 'd' || *format == 'i')
count += print_number(args);
else if (*format == 'b')
{
    unsigned int num = va_arg(args, unsigned int);
    count += print_binary(num);
}
else
{
count += write(1, "%", 1);
count += write(1, format, 1);
}
}
else
{
count += write(1, format, 1); /* Regular character */
}
format++;
}
va_end(args);
return (count);
}
