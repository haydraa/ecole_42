#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(int	c)
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

int	ft_putstr(char *str)
{
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	else 
		write (1, str, ft_strlen(str));
	return (ft_strlen(str));
}

void	recu(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) = 11;
	}
	else if (nbr < 0)
	{
		*len += ft_putchar('-');
		recu(-nbr, len);
	}
	else if (nbr >= 10)
	{
		recu(nbr / 10, len);
		(*len) += ft_putchar((nbr % 10) + 48);
	}
	else
		(*len) += ft_putchar(nbr + 48);
}

int	ft_putnbr(int nbr)
{
	int len = 0;
	recu(nbr, &len);
	return (len);
}

void	rec(unsigned int nbr, char *base, int *len)
{
	char i;
	if (nbr > 15)
		rec(nbr /16, base, len);
	i = base[nbr % 16];
	(*len) += ft_putchar(i);
}

int	ft_putbase(unsigned int nbr, char *base)
{
	int len = 0;
	rec(nbr, base, &len);
	return (len);
}

int	ft_check_format(va_list *arg, int c)
{
	int ret = 0;
	if (c == 'd')
		ret += ft_putnbr(va_arg(*arg, int));
	else if (c == 's')
		ret += ft_putstr(va_arg(*arg, char *));
	else if (c == 'x')
		ret += ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef");
	else
		ret += write(1, &c, 1);
	return (ret);
}

int ft_printf(char *format, ...)
{
	int i = 0;
	int ret = 0;
	va_list arg;
	
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret += ft_check_format(&arg ,format[i]);
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}	

#include <stdio.h>

int main()
{
	ft_printf("%s %d %% %x\n", "los", -15665, 15665);
	printf("%s %d %% %x\n", "los", -15665, 15665);
}
