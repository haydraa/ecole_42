/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:43:56 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/07 12:46:17 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int star, size_t len)
{
	char	*dest;
	int		x;

	x = star + len;
	if (s == NULL)
		return (NULL);
	if ((int)star >= ft_strlen(s) || len <= 0)
		return (ft_strdup(""));
	if (x > ft_strlen(s))
	{
		dest = malloc(sizeof(char) * (ft_strlen(s) - star + 1));
		if (dest == NULL)
			return (NULL);
		ft_strlcpy(dest, (s + star), ft_strlen(s) - star + 1);
		return (dest);
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, (s + star), len + 1);
	return (dest);
}
