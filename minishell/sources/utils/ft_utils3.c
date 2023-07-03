/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:05 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/25 10:02:24 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strjoin_c(char *s1, char c)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i++] = c;
	str[i] = '\0';
	return (str);
}

char	*ft_malloc_str(char *s1)
{
	char	*str;
	int		i;

	i = -1;
	if (s1 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_1ststrjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '/';
	i++;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	str_diff(char *str1, char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (str1[i] != str2[i])
		return (1);
	return (0);
}

void	ft_putendl(char *s)
{
	int	nbr;

	nbr = 0;
	if (s)
	{
		while (s[nbr])
		{
			write(1, &s[nbr], 1);
			nbr++;
		}
		write(1, "\n", 1);
	}
}
