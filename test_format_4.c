#include "main.h"
#include <limits.h>

int main(void)
{
    unsigned int num = 1024;
    unsigned int zero = 0;
    unsigned int max = UINT_MAX;

    _printf("1. Unsigned decimal: %u\n", num);
    _printf("2. Octal: %o\n", num);
    _printf("3. Hex (lower): %x\n", num);
    _printf("4. Hex (upper): %X\n", num);

    _printf("5. Zero in all formats: %u %o %x %X\n", zero, zero, zero, zero);

    _printf("6. Max unsigned: %u %o %x %X\n", max, max, max, max);

    return (0);
}
