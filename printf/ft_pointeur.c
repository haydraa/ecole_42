/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:56:30 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/12 20:01:02 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pointeur(unsigned long long p, int *len)
{
	char			*base;
	char			i;
	unsigned long	j;

	base = "0123456789abcdef";
	j = ft_strlen(base);
	if (p >= j)
	{
		pointeur(p / j, len);
	}
	i = base[p % j];
	*len += ft_putchar(i);
}

int	ft_pointeur(unsigned long long p)
{
	int	len;

	len = 2;
	if (p == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putchar('0');
	ft_putchar('x');
	pointeur(p, &len);
	return (len);
}
