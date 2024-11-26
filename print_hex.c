#include<unistd.h>
void	print_hex(long	n,char	*base)
{
	unsigned long nb;
	if(n<0)
	{
		write(1,"-",1);
		nb=-n;
	}
	else
		nb=n;
	if(nb >=16)
	{
		print_hex(nb /16,base);
		write(1,&base[nb%16],1);
	}
	else
		write(1,&base[nb],1);
}
void	print_hex_low(long n)
{
	print_hex(n,"0123456789abcdef");
}
void	print_hex_upp(long n)
{
	print_hex(n,"0123456789ABCDEF");
}
