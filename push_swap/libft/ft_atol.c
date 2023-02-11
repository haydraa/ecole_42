/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:25:02 by jghribi           #+#    #+#             */
/*   Updated: 2023/02/11 19:26:25 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	white_space(const char nptr)
{
	if ((nptr > 8 && nptr < 14) || nptr == ' ')
		return (0);
	return (1);
}

long 	ft_atol(const char *nptr)
{
	int		i;
	int		s;
	long 	result;

	i = 0;
	s = 1;
	result = 0;
	while ((white_space(nptr[i]) == 0))
			i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * s);
}
