/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:58:08 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/07 12:00:00 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 < str2)
	{
		ft_memcpy(str1, str2, n);
	}
	else
	{
		while (n > 0)
		{
			str1[n - 1] = str2[n - 1];
			n--;
		}
	}
	return (str1);
}
