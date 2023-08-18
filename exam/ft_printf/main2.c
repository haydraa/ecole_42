#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(int c)
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
	return (write(1, str, ft_strlen(str)));
}

void	rec(unsigned int nbr, char *bas, int *len)
{
	char i;
	long n;

	if (nbr > 15)
		rec(nbr / 16, bas, len);
	i = bas[n % 16];
	(*len) += ft_putchar(i);
}
int ft_putbase(unsigned int nbr, char *bas)
{
	int len;

	len = 0;
	rec(nbr, bas, &len);
	return (len);
}

void	recu(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len = 11;
	}
	else if(nbr < 0)
	{
		len += ft_putchar('-');
		recu(-nbr, len);
	}
	else if (nbr >= 10)
	{
		recu(nbr / 10, len);
		len += ft_putchar((nbr % 10) + 48);
	}
	else
		*len += ft_putchar(nbr + 48);
}

int	ft_putnbr(int	nbr)
{
	int len;

	len = 0;
	recu(nbr, &len);
	return (len);
}

int	ft_check_format(va_list *arg, int c)
{
	int len;

	len = 0;
	if (c == 's')
		len += ft_putstr(va_arg(*arg, char *));
	else if (c == 'd')
		len += ft_putnbr(va_arg(*arg , int));
	else if (c == 'x')
		len += ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef");
	else
		len += write(1 ,&c ,1);
	return (len);
}


int	ft_printf(char *format, ...)
{
	int i;
	int ret;
	va_list	arg;

	ret = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if(format[i] == '%')
		{
			i++;
			ft_check_format(&arg, format[i]);
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}


int main(void)
{
	ft_printf("%d %s %x\n", -495, "los  ", 495);
}
