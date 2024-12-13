#include <unistd.h>

int	print_hex(int n, char *base)
{
	unsigned int nb;
	int	l;

	l = 0;
	nb =(unsigned int) n;
	if (nb >= 16)
	{
		l += print_hex(nb / 16, base);
		write(1, &base[nb % 16], 1);
	}
	else
		write(1, &base[nb], 1);
	return (++l);
}
int	print_hex_low(int n)
{
	return (print_hex(n, "0123456789abcdef"));
}
int	print_hex_upp(int n)
{
	return (print_hex(n, "0123456789ABCDEF"));
}
