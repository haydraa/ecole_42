/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:21:03 by marvin            #+#    #+#             */
/*   Updated: 2022/10/07 12:14:23 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*convert;
	char	*dest;
	int		j;

	convert = (char *)src;
	j = ft_strlen(convert);
	dest = malloc(sizeof(char) * j + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, convert, j + 1);
	dest[j] = '\0';
	return (dest);
}
