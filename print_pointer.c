#include <unistd.h>

int	print_pointer(void *p)
{
	char	*s;
	long	n;
	int l;

	s = (char *)p;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	n = (long)s;
	write(1, "0x", 2);
	l=print_hex_low(n);
	return (2 +l);
}
/*#include<stdio.h>
int main()
{
	char *s="hello";
	int d= print_pointer(s);
	printf("\n%d\n",d);
}*/
