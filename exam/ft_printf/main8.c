#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_putstr(char *str)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
	
void	rec_nbr(int *len, int nbr)
{
	if (nbr < 0)
	{
		(*len) += ft_putchar('-');
		rec_nbr(len, -nbr);
	}
	else if (nbr >= 10)
	{
		rec_nbr(len, nbr / 10);
		(*len) += ft_putchar((nbr % 10) + 48);
	}
	else
		(*len) += ft_putchar(nbr + 48);
}

int	ft_putnbr(int nbr)
{
	int len;
	rec_nbr(&len, nbr);
	return (len);
}

void	rec_base(int *len, unsigned int nbr, char *base)
{
	char i;
	long n;
	n = (long)nbr;

	if (n > 15)
		rec_base(len, nbr / 16, base);
	i = base[nbr % 16];
	(*len) += ft_putchar(i);
}

int ft_putbase(unsigned int nbr, char *base)
{
	int len;
	rec_base(&len, nbr, base);
	return (len);
}

int check_format(va_list *arg, int c)
{
	int ret = 0;

	if (c == 'd')
		ret += ft_putnbr(va_arg(*arg, int));
	else if (c == 's')
		ret += ft_putstr(va_arg(*arg, char *));
	else if (c == 'x')
		ret += ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef");
	else
		ret += ft_putchar('%');
	return (ret);
}

int ft_printf(char *format, ...)
{
	int ret = 0;
	int i = 0;
	va_list arg;

	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret += check_format(&arg, format[i]);
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}

int main ()
{
	ft_printf("%s %d  %x %qqq\n", "lol", -42, -42);
	printf("%s %d  %x %qqq%", "lol", -42, -42);
}
