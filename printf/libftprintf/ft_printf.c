#include "libftprintf.h"
#include <stdio.h>
void check_format(va_list *arg, char s)
{
	if (s == 'c')
		ft_putchar(va_arg(arg, char));
	if (s == 's')
		ft_putstr(va_arg(arg, char*));
	if (s == 'p')
		ft_pointeur(va_arg(arg, unsigned long));
	if (s == 'd')
		ft_putnbr(va_arg(arg, int));
	if (s == 'i')
		ft_putnbr(va_arg(arg, int));
	if (s == 'u')
		ft_putnbr(va_arg(arg, unsigned int));
	if (s == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int));
	if (s == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int));
	if (s == '%')
		write(1 ,'%', 1);
}
	
int ft_printf(const char *format, ...)
{
	va_list arg;
	int i;
	
	char c;
	char *s;
	int s_size;
	
	i = 0;
	s_size = 0;
	va_start (arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{	
			//ft_check_format(arg, format[i + 1]);
			if (format[i + 1] == 'c')
			{
				c = va_arg(arg, int);
				write(1, &c, 1);
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(arg, char *);
				while (s[s_size])
					s_size++;
				write(1, s, s_size);
			}
			i++;
		}	
		else
			write(1, &format[i], 1);
			i++;		
	}
	va_end(arg);
	return 1;
}

int main()
{
	char *c = "salut";
    	ft_printf("ssss%sss ", c);
}
