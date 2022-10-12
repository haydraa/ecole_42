/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:08:39 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/12 18:43:27 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static void recu(int nb, int *len)
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
		*len += ft_putchar(nb % 10 + 48);
	}
	else
		*len += ft_putchar(nb + 48);
}
int	ft_putnbr(int nb)
{
	int len;

	len = 0;
	recu(nb, &len);
	//printf("\nlen : %d\n" , len);
	return(len);
}
/*
int main()
{
	ft_printf("len : %d\n", ft_printf(" %d ", -1));
}*/

