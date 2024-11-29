#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	its_formatting(char c)
{
	char	*s;
	int		i;

	s = "duixX%csp";
	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}
static unsigned int	count_arg(char *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == '%' && its_formatting(s[i + 1]))
			k++;
		i++;
	}
	return (k);
}
int	what_function(char c, va_list arg)
{
	int d;

	if (c == 'd' || c == 'u' || c == 'i')
	{
		d = va_arg(arg, int);
		return print_int(d);
	}
	else if (c == 'X')
	{
		d = va_arg(arg, int);
		return print_hex_upp(d);
	}
	else if (c == 'c')
	{
		char o;
		o = va_arg(arg, int);
		return print_char(o);
	}
	else if (c == 'p')
	{
		void *p;
		p = va_arg(arg, void *);
		return print_pointer(p);
	}
	else if (c == '%')
	{
		return print_percent();
	}
	else if (c == 'x')
	{
		d = va_arg(arg, int);
		return print_hex_low(d);
	}
	else if (c == 's')
	{
		char *s;
		s = va_arg(arg, char *);
		return print_string(s);
	}
}
int	ft_printf(char *s, ...)
{
	va_list args;
	int	j;
	int l;

	if (!s)
	{
		return -1;
	}
	va_start(args, count_arg(s));
	j = 0;
	l=0;
	while (s[j])
	{
		if (s[j] == '%' && its_formatting(s[j + 1]))
		{
			l+=what_function(s[j + 1], args);
			j += 2;
		}
		else
		{
			write(1, &s[j++], 1);
			l++;
		}
	}
	return l;
}
/*#include<stdio.h>
int main(void)
{
	char c='c';
	int dc=ft_printf("s:%s n:%d p:%p c:%c x:%x \n","hello",123,&c,'c',2025);
	printf("%d\n",dc);
	dc=printf("s:%s n:%d p:%p c:%c x:%x \n","hello",123,&c,'c',2025);
        printf("%d\n",dc);
}*/

