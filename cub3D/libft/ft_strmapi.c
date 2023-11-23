/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:27:55 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/23 10:26:52 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;
	int				len;

	if (s == NULL || f == NULL )
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, len + 1);
	while (dest[i])
	{
		dest[i] = f(i, dest[i]);
		i++;
	}
	return (dest);
}
