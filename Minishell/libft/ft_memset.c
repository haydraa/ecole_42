/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:31:33 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 18:29:13 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	char			*str;
	size_t			i;

	ch = (unsigned char)c;
	str = (char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = ch;
		i++;
	}
	return (b);
}
