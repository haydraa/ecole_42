/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:43:56 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/09 14:46:19 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		x;

	x = start + len;
	if (s == NULL)
		return (NULL);
	if ((int)start >= ft_strlen(s) || len <= 0)
		return (ft_strdup(""));
	if (x > ft_strlen(s))
	{
		dest = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (dest == NULL)
			return (NULL);
		ft_strlcpy(dest, (s + start), ft_strlen(s) - start + 1);
		return (dest);
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, (s + start), len + 1);
	return (dest);
}
