#include <unistd.h>
#include"ft_printf.h"
#include<limits.h>

int     print_hex_long(long n, char *base)
{
        int     l;

	unsigned long nb;

	nb=(unsigned long)n;
        l = 0;
        if (nb >= 16)
        {
                l += print_hex_long(nb / 16, base);
                write(1, &base[nb % 16], 1);
        }
        else
                write(1, &base[nb], 1);
        return (++l);
}

int	print_pointer(void *p)
{
	//char	*s;
	long n;
	int l;

	//s = (char *)p;
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = (long)(p);
	write(1, "0x", 2);
	l=print_hex_long(n,"0123456789abcdef");
	return (2 +l);
}
