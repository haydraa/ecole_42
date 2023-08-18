#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c ,1));
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

int ft_putstr(char *str)
{
	if (str == NULL)
	{
		write(1, "(null)", 1);
		return (6);
	}
	else
		write(1, str, ft_strlen(str));
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
		(*len) += ft_putchar('-');
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

void rec(unsigned int nbr, char *base, int *len)
{
	char i;
	if (nbr > 15)
		rec(nbr / 16, base, len);
	i = base[nbr % 16];
	(*len) += ft_putchar(i);
}

int ft_putnbr(int nbr)
{
	int len = 0;
	recu(nbr, &len);
	return(len);
}

int ft_putbase(unsigned int nbr, char *base)
{
	int len = 0;
	rec(nbr, base, &len);
	return(len);
}

int	check_format(va_list *arg, int c)
{
	int	ret = 0;
	if (c == 'd')
		ret += ft_putnbr(va_arg(*arg, int));
	else if (c == 'x')
		ret += ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef");
	else if (c == 's')
		ret += ft_putstr(va_arg(*arg, char *));
	else
		ret += ft_putchar(c);
	return (ret);
}

int ft_printf(char *str, ...)
{
	int ret = 0;
	int i = 0;
	va_list arg;
	
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret += check_format(&arg, str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}

#include <stdio.h>
int main()
{
	ft_printf("%s %d %x\n", "losl", -4567, 4567);
	printf("%s %d %x\n", "losl", -4567, 4567);
}
