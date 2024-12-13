#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

int print_char(char c);
int print_int(int n);
int print_hex(long n, char *base);
int print_hex_low(long n,int on);
int print_hex_upp(long n);
int print_pointer(void *p);
int print_percent(void);
unsigned long ft_strlen(char *s);
int print_string(char *s);
int     print_u_int(unsigned int n);
int ft_printf(const char *s, ...);

#endif

