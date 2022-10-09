/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:42:51 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/09 12:24:17 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long int nb)
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

static void	ft_fill(long nb, char *dest, int *i)
{
	if (nb > 9)
	{
		ft_fill(nb / 10, dest, i);
		ft_fill(nb % 10, dest, i);
	}
	else
	{	
		dest[*i] = nb + '0';
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	int		d;
	char	*dest;
	long	nb;
	int		i;

	nb = n;
	d = len(nb);
	dest = malloc((d + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[d--] = '\0';
	i = 0;
	if (nb < 0)
	{
		dest[i++] = '-';
		nb = nb * -1;
	}
	ft_fill (nb, dest, &i);
	dest[i] = '\0';
	return (dest);
}
