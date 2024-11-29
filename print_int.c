#include <unistd.h>

int	print_int(int n)
{
	unsigned int	nb;
	char			*base;
	int				l;

	l = 0;
	base = "0123456789";
	if (n < 0)
	{
		l = (int)write(1, "-", 1);
		nb = -1 * n;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		l += print_int(nb / 10);
		write(1, &base[nb % 10], 1);
	}
	else
		write(1, &base[nb], 1);
	return (++l);
}
/*#include<stdio.h>
int	main(void)
{
	printf(" \n%d",print_int(-123456));
	printf(" \n%d",print_int(12));
	printf(" \n%d",print_int(123));
	printf(" \n%d",print_int(0));
}*/
