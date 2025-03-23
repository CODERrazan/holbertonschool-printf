#include "main.h"
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
int count = 0; /* Tracks characters printed */
if (!format)
return (-1); 
va_start(args, format); 
while (*format)
{
if (*format == '%') 
{
format++; 
if (!*format)
return (-1); 
if (*format == 'c') 
{
char c = va_arg(args, int);
count += write(1, &c, 1);
}
else if (*format == 's') 
{
char *str = va_arg(args, char *);
if (!str)
str = "(null)"; 
while (*str)
count += write(1, str++, 1);
}
else if (*format == '%') 
{
count += write(1, "%", 1);
}
else /* Unknown specifier, print literally */
{
count += write(1, "%", 1);
count += write(1, format, 1);
}
}
else
{
count += write(1, format, 1);
}
format++;
}
va_end(args); /* Clean up */
return (count);
}
