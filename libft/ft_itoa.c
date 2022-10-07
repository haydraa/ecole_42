/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:42:51 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/07 10:47:12 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long int nb)
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

char	*ft_itoa(int n)
{
	int		d;
	char	*dest;
	long	nb;

	nb = n;
	d = len(nb);
	dest = malloc((d +1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[d--] = '\0';
	if (nb == 0)
		return ("0");
	if (nb < 0)
	{
		dest[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		dest[d--] = 48 + (nb % 10);
		nb = nb / 10;
	}	
	return (dest);
}
