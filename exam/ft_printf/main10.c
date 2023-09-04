#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_putchar(int c)
{
	return (write(1, &c, 1));
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

void	rec_nbr(int nbr, int *len)
{
	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
	}
	else if (nbr < 0)
	{
		(*len) += ft_putchar('-');
		rec_nbr(-nbr, len);
	}
	else if (nbr >= 10)
	{
		rec_nbr(nbr / 10, len);
		(*len) += ft_putchar((nbr % 10) + 48);
	}
	else
		(*len) += ft_putchar (nbr + 48);
}

int ft_putnbr(int nbr)
{
	int len = 0;
	rec_nbr(nbr , &len);
	return (len);
}

void	rec_base(unsigned int nbr, char *base, int *len)
{
	char i;
	long n;
	n = (long)nbr;
	if (nbr > 15)
		rec_base(nbr / 16, base, len);
	i = base[nbr % 16];
	(*len) += ft_putchar(i);
}

int ft_putbase(unsigned int nbr, char *base)
{
	int len = 0;
	rec_base(nbr,base , &len);
	return (len);
}

int	check_format(int c, va_list *arg)
{
	int ret = 0;

	if (c == 's')
		ret += ft_putstr(va_arg(*arg, char *));
	else if (c == 'd')
		ret += ft_putnbr(va_arg(*arg, int));
	else if (c == 'x')
		ret += ft_putbase(va_arg(*arg, unsigned int), "0123456789abcdef");
	else
		ret += ft_putchar(c);
	return (ret);
}

int	ft_printf(const char *format, ...)
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

	x =  ft_printf("%s %d %x\n", "losl", INT_MIN - 1, 4567);
   	printf("%d\n",x);
    x =  printf("%s %d %x\n", "losl", INT_MIN  - 1, 4567);
   	printf("%d\n",x);
}  
