/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:55:32 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/07 11:57:35 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t i)
{
	char	*s;
	char	*d;
	size_t	j;

	s = (char *)src;
	d = (char *)dest;
	j = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (j < i)
	{
		d[j] = s[j];
		j++;
	}
	return (dest);
}
