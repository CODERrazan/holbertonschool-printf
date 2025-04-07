#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function prototype for _printf */
int _printf(const char *format, ...);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n);
int print_custom_string(char *str);
int print_pointer(void *ptr);
int print_number_with_flags(va_list args, int plus, int space);
int convert_base(unsigned int num, int base, int uppercase, int hash_flag);

#endif /* MAIN_H */
