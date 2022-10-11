#include "libftprintf.h"
#include <stdio.h>
void check_format(int argv, ...)
{
	va_list arg;

	va_start(arg,argv);
	if (arg == 'c')
		ft_putchar(arg = va_arg(arg, char));
	if (arg == 's')
		ft_putstr(arg = va_arg(arg, char*));
	if (arg == 'p')
		
	if (arg == 'd')
		ft_putnbr(arg = va_arg(arg, int));
	if (arg == 'i')
		ft_putnbr(arg = va_arg(arg, int));
	if (arg == 'u')
		ft_putnbr(arg = va_arg(arg, unsigned int));
	if (arg == 'x')
		ft_putnbr_base(arg = va_arg(arg, int));
	if (arg == 'X')
		ft_putnbr_base(arg = va_arg(arg, int));
	if (arg == '%')
		write(1 ,'%', 1);
}
	
int ft_prinf(const char *format, ...)
{
	va_list arg;
	int i;

	i = 0;
	va_start (arg, format);
	while (*format)
	{
		if (*format == '%')
		{	
			format = ft_check_format(arg, format + 1); 
		}			
	}
	return 1;
}

int main()
{
    const char *s = "sssssssssssss";
	printf(ft_strlen(s));
}
