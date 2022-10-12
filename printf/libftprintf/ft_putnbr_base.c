/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:18:36 by jghribi           #+#    #+#             */
/*   Updated: 2022/09/04 11:59:37 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_base(int nbr, const char *base)
{
	int		j;
	char	i;
	long	n;
	n = (long)nbr;
	j = ft_strlen(base);
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	else if (n >= j)
	{
		ft_putnbr_base(n / j, base);
	}
	i = base[n % j];
	ft_putchar_fd(1,i);
}

