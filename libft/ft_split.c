/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:18:40 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/07 20:36:29 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	get_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c)
				s++;
			i++;
		}
		while (*s == c)
			s++;
	}
	return (i);
}
char	**ft_split(char const *s, char c)
{
	int		y;
	int		i;
	int		j;
	char	**dest;

	if (s == NULL)
		return (NULL);
	dest = malloc(sizeof(char *) * (get_word(s, c) + 1));
	//printf("%d", get_word(s, c));
	if (dest == NULL)
		return (NULL);
	y = 0;
	j  = 0;
	while (s[y] && j < get_word(s, c))
	{
		while (s[y] == c)
			y++;
		i = 0;
		while (s[y + i] != c)
			i++;
		dest[j] = malloc(sizeof(char) * (i + 1)); 
		ft_strlcpy(dest[j], s + y, i + 1);
		j++;
		y = y + i + 1;
	}
	dest[j] = NULL;
	return (dest);
}

int main(void)
{
	char **strs;
	int	i;

	strs = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	i = 0;
	while (strs[i])
	{
		printf("%s-", strs[i]);
		i++;
	}
	return (0);
}
