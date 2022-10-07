/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:50:04 by marvin            #+#    #+#             */
/*   Updated: 2022/10/07 12:43:09 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		x;
	char	*dest;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s1);
	while (check(s1[i], set) == 1)
		i++;
	while (check(s1[j - 1], set) == 1)
		j--;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	x = j - i;
	dest = ft_calloc(sizeof(char), (x + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, (s1 + i), x + 1);
	return (dest);
}
