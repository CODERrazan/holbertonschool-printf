#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function prototype for _printf */
int _printf(const char *format, ...);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n);
int convert_base(unsigned int n, int base, int uppercase);
int print_custom_string(char *str);
int print_pointer(void *ptr);

#endif /* MAIN_H */
