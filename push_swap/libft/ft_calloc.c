/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:31:49 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/07 10:34:57 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (nmemb == 0 || size <= 0)
		return (malloc(0));
	if (!(nmemb * size / size == nmemb))
		return (NULL);
	dest = malloc(size * nmemb);
	if (dest == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
