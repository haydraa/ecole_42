/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:36:14 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 18:44:35 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = (0);
	while (*s)
	{
		if (*s == (char)c)
			save = (char *)s;
		s++;
	}
	if (save)
		return (save);
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
