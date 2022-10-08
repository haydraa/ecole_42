/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:45:17 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/08 17:13:25 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_word(const char *s, char c)
{
	int	i;
	int	j;
	int	y;

	y = -1;
	i = 0;
	j = 0;
	while (s[++y])
	{
		if (s[y] != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (s[y] == c)
			j = 0;
	}
	return (i);
}

static char	*get_word(const char *s, int st, int f)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((f - st + 1) * sizeof(char));
	while (st < f)
		word[i++] = s[st++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		idx[3];
	char	**dest;

	if (!s)
		return (0);
	dest = malloc((ft_len_word(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (0);
	idx[0] = 0;
	idx[1] = 0;
	idx[2] = -1;
	while (idx[0] <= ft_strlen(s))
	{
		if (s[idx[0]] != c && idx[2] < 0)
			idx[2] = idx[0];
		else if ((s[idx[0]] == c || idx[0] == ft_strlen(s)) && idx[2] >= 0)
		{
			dest[idx[1]++] = get_word(s, idx[2], idx[0]);
			idx[2] = -1;
		}
		idx[0]++;
	}
	dest[idx[1]] = 0;
	return (dest);
}
