#include <stdarg.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return(i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int		ft_putstr(char *str)
{
	if(str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

void	recu(int nb ,int *len)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len = 11;
	}
	else if (nb < 0)
	{
		*len += ft_putchar('-');
		recu(-nb, len);
	}
	else if (nb >= 10)
	{
		recu(nb / 10, len);
		*len = ft_putchar((nb % 10) + 48);
	}
	else 
		*len += ft_putchar(nb + 48);

}

int	ft_putnbr(int	nb)
{
	int len;

	len = 0;
	recu(nb, &len);
	return (len);
}


void	rec(unsigned int nbr, const char *base, int *len)
{
	char i;
	long n;
	n = (long)nbr;
	if (n > 15)
		rec(n / 16, base, len);
	i = base[n % 16];
	(*len) +=ft_putchar(i);
}

int	ft_base(unsigned int nbr, const char *base)
{
	int len;

	len = 0;
	rec(nbr, base, &len);
	return (len);
}

int	ft_check_format(va_list *arg, int c)
{
	int ret;

	ret = 0;
	if (c == 's')
		ret += ft_putstr(va_arg(*arg, char *));
	if (c == 'x')
		ret += ft_base(va_arg(*arg, unsigned int), "0123456789abcdef");
	if (c == 'd')
		ret += ft_putnbr(va_arg(*arg, int));
	if (c == '%')
		ret += write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int i;
	int ret;
	va_list	arg;

	ret = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret += ft_check_format(&arg, format[i]);
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
	ft_printf("%s%d%s%x%s", "lol ", 44455 , " ", 42, "\n" );
}
