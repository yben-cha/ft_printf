#include<unistd.h>
void	print_int(int	n)
{
	unsigned int	nb;
	char	c;
	if(n < 0)
	{	write(1,"-",1);
		nb=-1*n;
	}
	else
		nb=n;
	if(nb >=10)
	{
		print_int(nb /10);
		c=(nb%10) +'0';
		write(1,&c,1);
	}
	else
	{
		c=nb +'0';
                write(1,&c,1);
	}
}
