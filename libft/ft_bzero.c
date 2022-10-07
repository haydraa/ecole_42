/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:27:00 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/07 10:36:04 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t i)
{
	unsigned char	*p;

	p = s;
	while (i > 0)
	{
		*p++ = '\0';
		i--;
	}
	return (s);
}
