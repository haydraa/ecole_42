#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int ft_strlen(char *c)
{
	int i = 0;
	while (c[i])
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
		write (1, str, ft_strlen(str));
	return (ft_strlen(str));
}

void	rec_nbr(int nbr, int *ret)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*ret) += 11;
	}
	else if (nbr < 0)
	{
		(*ret) += ft_putchar('-');
		rec_nbr(-nbr, ret);
	}
	else if (nbr >= 10)
	{
		rec_nbr(nbr / 10, ret);
		(*ret) += ft_putchar((nbr % 10) + 48);
	}
	else 
		(*ret) += ft_putchar(nbr + 48);
}

int	ft_putnbr(int nbr)
{
	int ret = 0;
	rec_nbr(nbr, &ret);
	return (ret);
}

void rec_base(unsigned int nbr, char *base, int *ret)
{
	char i;

	if (nbr > 15)
		rec_base(nbr / 16, base, ret);
	i = base[nbr % 16];
	(*ret) += ft_putchar(i);
}

int ft_putbase(unsigned int nbr, char *base)
{
	int ret = 0;
	rec_base(nbr, base, &ret);
	return (ret);
}

int	check_format(int c, va_list *arg)
{
	int	ret = 0;
	
	if (c == 's')
		ret += ft_putstr(va_arg(*arg, char*));
	else if (c == 'd')
		ret += ft_putnbr(va_arg(*arg, int));
	else if (c == 'x')
		ret += ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef");
	else
		ret += ft_putchar(c);
	return (ret);
}

int ft_printf(const char *format, ...)
{
	int ret;
	int i;
	va_list arg;

	ret = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if(format[i] == '%')
		{
			i++;
			ret += check_format(format[i], &arg);
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}

int main()
{
	int x = 0;

	x = ft_printf("%s %d %x\n", "losl", -21478483648, -4567);
	printf("%d\n", x);
    x = printf("%s %d %x\n", "losl", -21478483648, -4567);
	printf("%d\n", x);
}
