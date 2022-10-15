/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:59:03 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/12 16:49:07 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list *arg, int s)
{
	int	ret;

	ret = 0;
	if (s == 'c')
		ret += ft_putchar(va_arg(*arg, int));
	if (s == 's')
		ret += ft_putstr(va_arg(*arg, char *));
	if (s == 'p')
		ret += ft_pointeur(va_arg(*arg, unsigned long));
	if (s == 'd' || s == 'i')
		ret += ft_putnbr(va_arg(*arg, int));
	if (s == 'u')
		ret += ft_putnbr1(va_arg(*arg, unsigned int));
	if (s == 'x')
		ret += ft_base(va_arg(*arg, unsigned int), "0123456789abcdef");
	if (s == 'X')
		ret += ft_base(va_arg(*arg, unsigned int), "0123456789ABCDEF");
	if (s == '%')
		ret += write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	va_list	arg;

	ret = 0;
	i = 0;
	va_start (arg, format);
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
