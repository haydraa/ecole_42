/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:48:44 by marvin            #+#    #+#             */
/*   Updated: 2022/09/30 15:27:00 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "libft.h"

void *ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *s; 
	size_t i;

	s = (unsigned char*) str;
	i = 0;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
		{
			return &s[i];
		}
		i++;
	}
	return NULL;
}
