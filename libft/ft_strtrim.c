/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:50:04 by marvin            #+#    #+#             */
/*   Updated: 2022/10/01 19:24:45 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int check(char s, char const *set)
{
	int i; 
	
	i = 0;
	while (set[i] != '\0')
	{
		if (s == set[i])
			return 1;
		i++;
	}
	return 0;
}

char *ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;
	int x;
	char *dest;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (s1 == NULL)
		return NULL;
	if (set == NULL)
		return (char*)s1;
	while ((check(s1[i],set) == 1))
		i++;
	while (check(s1[j], set) == 1)
		j--;
	dest = malloc(sizeof(char) * (j - i) + 1);
	if (dest == NULL)
		return (NULL);
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (i <= j)
	{
		dest[x] = s1[i];
		i++;
		x++; 
	}
	dest[x] = '\0';
	return dest;
}
