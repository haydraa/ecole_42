/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:18:36 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/12 20:18:10 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rec(unsigned int nbr, const char *base, int *len)
{
	char	i;
	long	n;
	
	n = (long)nbr;
	if (n > 15)
		rec(n / 16, base, len);
	i = base[n % 16];
	(*len) += ft_putchar(i);
}

int	ft_print_base(unsigned int nbr, const char *base)
{
	int	len;

	len = 0;
	rec(nbr, base, &len);
	return (len);
}
