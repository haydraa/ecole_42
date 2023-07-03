/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:45:17 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/09 14:44:12 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

static char	*get_word(const char *s, size_t st, size_t f)
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

static void	ft_unit(size_t *i, size_t *j, size_t *x)
{
	*i = 0;
	*j = 0;
	*x = -1;
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		x;
	char		**dest;

	if (!s)
		return (0);
	dest = malloc((ft_len_word(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (0);
	ft_unit(&i, &j, &x);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && x < 0)
			x = i;
		else if ((s[i] == c || i == ft_strlen(s)) && x >= 0)
		{
			dest[j++] = get_word(s, x, i);
			x = -1;
		}
		i++;
	}
	dest[j] = 0;
	return (dest);
}
