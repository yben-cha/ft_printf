#include<unistd.h>
unsigned long	ft_strlen(char *s)
{
	unsigned long	i;

	i=0;
	while(s[i])
		i++;
	return i;
}
void	print_string(char *s)
{
	if(!s)
	{
		write(1,"(null)",6);
		return;
	}
	write(1,s,ft_strlen(s));
}
