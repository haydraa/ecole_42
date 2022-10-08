/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:50:26 by marvin            #+#    #+#             */
/*   Updated: 2022/10/08 17:28:45 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t size)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = str;
	while (size > 0)
	{
		p[i] = (unsigned char) value;
		size--;
		i++;
	}
	return (str);
}
