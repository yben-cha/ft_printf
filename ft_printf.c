#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
static unsigned int count_arg(char *s)
{
	int	i=0;
	int	k=0;
	while(s[i])
	{
		if(s[i]=='%')
			k++;
		i++;
	}
	return k;
}
void	what_function(char c, va_list arg)
{
	if(c=='d')
	{
		int	d=va_arg(arg,int);
		print_int(d);
	}
	else if(c=='x')
	{
		int	d=va_arg(arg,int);
		print_hex_low(d);
	}
	else if(c=='s')
	{
		char *s=va_arg(arg,char *);
		print_string(s);
	}
	else
		print_string("bad operator");
}
void	ft_printf(char *s,...)
{
	int	i;
	if(!s)
	{
		write(1,"(null)",6);
		return;
	}
	i=count_arg(s);
	if(i)
	{
		va_list args;
		va_start(args,i);
		int	j=0;
		while(s[j])
		{
			if(s[j]=='%' && s[j+1])
			{
				what_function(s[j+1],args);
				j +=2;
			}
			else
				write(1,&s[j++],1);
		}
	}
}
int main(void)
