/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:55:14 by jghribi           #+#    #+#             */
/*   Updated: 2022/09/30 19:41:56 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t lenli;

	lenli = ft_strlen((char*)little);
	i = 0;
	j = 0;
	if (little[0] == '\0')
		return (char*)big;
	while (i < len)
	{
		if (big[i] == little[0])
		{
			while (little[j] == big[i + j] && (i + j) < len)
			{
				j++;
				if ( lenli == j)
					return ((char*)&big[i]);
			}
			j = 0;
		}
		i++;
	}
	return 0;
}
