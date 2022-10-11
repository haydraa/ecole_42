#include "libftprintf.h"


void check_format(int argv, ...)
{
	va_list arg;

	va_start(arg,argv)
	if (arg == 'c')
		ft_putchar(arg = va_arg(args char));
	if (arg == 's')
		ft_putstr(arg = va_arg(argc char*));
	if (arg == 'p')
		
	if (arg == 'd')
		ft_putnbr(arg = va_arg(args int));
	if (arg == 'i')
		ft_putnbr(arg = va_arg(args int));
	if (arg == 'u')
		ft_putnbr(arg = va_arg(args unsigned int));
	if (arg == 'x')
		ft_putnbr_base(arg = va_arg(args int));
	if (arg == 'X')
		ft_putnbr_base(arg = va_arg(args int), char X);
	if (arg == '%')
		write(1 ,'%', 1);

	}
}
	
int ft_prinf(const char *format, ...)
{
	va_list parinfo;
	int i;

	i = 0;
	va_start (parinfo, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			if(check_format(format[i + 1]) == 1)

				

			
	}
	return 1;
}

int main()
{
    const char *s = "sssssssssssss"
	printf (ft_strlen(s));
}
