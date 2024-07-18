#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string composed of zero or more directives
 * 
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    const char *ptr;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++) {
        if (*ptr == '%') {
            ptr++;
            switch (*ptr) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    if (s == NULL)
                        s = "(null)";
                    while (*s) {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default: {
                    putchar('%');
                    putchar(*ptr);
                    count += 2;
                    break;
                }
            }
        } else {
            putchar(*ptr);
            count++;
        }
    }

    va_end(args);
    return count;
}


