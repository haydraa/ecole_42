/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:01:04 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/08 17:29:30 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen((const char *)s1) + ft_strlen((const char *)s2));
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen((const char *)s1) + 1);
	ft_strlcat(result, s2, len + 1);
	return (result);
}
