#include <unistd.h>

int	print_hex(long n, char *base)
{
	unsigned long	nb;
	int				l;

	l = 0;
	if (n < 0)
	{
		l = (int)write(1, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 16)
	{
		l += print_hex(nb / 16, base);
		write(1, &base[nb % 16], 1);
	}
	else
		write(1, &base[nb], 1);
	return (++l);
}
int	print_hex_low(long n)
{
	return (print_hex(n, "0123456789abcdef"));
}
int	print_hex_upp(long n)
{
	return (print_hex(n, "0123456789ABCDEF"));
}
/*#include<stdio.h>
int	main(void)
{
	int d=print_hex_low(15);
	printf("\n%d\n",d);
	d=print_hex_low(2024);
	printf("\n%d\n",d);
	d=print_hex_low(20252026);
	printf("\n%d\n",d);
}*/
