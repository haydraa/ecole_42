/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:37:59 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/23 13:22:23 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) \
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	else
	{
		while (i < ft_strlen(src) && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*result;

	result = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, sizeof(char) * (ft_strlen(s1) + 1));
	return (result);
}

char	*ft_replace_word(char *str, int start, int len, char *word)
{
	t_var	var;

	var.i = 0;
	var.j = 0;
	var.k = 0;
	var.newlen = ft_strlen(str) - len + ft_strlen(word);
	var.result = malloc(sizeof(char) * (var.newlen + 1));
	while (str[var.k])
	{
		if (var.k == start)
		{
			while (word && word[var.j])
				var.result[var.i++] = word[var.j++];
			var.k = start + len;
		}
		if (str[var.k] != '\0')
			var.result[var.i++] = str[var.k++];
	}
	var.result[var.i] = '\0';
	free(str);
	return (var.result);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
