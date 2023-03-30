#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _precision(const char *format, int *i, va_list list);
int print_int(va_list list, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list list, char buffer[], int flags, int width, int precision, int size);
int print_char(va_list list, char buffer[], int flags, int width, int precision, int size)

#endif /* MAIN_H */
