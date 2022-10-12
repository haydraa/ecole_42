/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:15:26 by marvin            #+#    #+#             */
/*   Updated: 2022/10/12 13:18:45 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i = 1;
	}
	while (nb != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int	ft_putnbr1(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr((n / 10));
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
	return (len (n));
}
