/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:50:04 by marvin            #+#    #+#             */
/*   Updated: 2022/09/29 12:50:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int get_first_postion(char *s, char *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] && set[j])
	{
		if (set[j] == s[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

int get_last_postion(char *s, char  *set)
{
	int i;
	int j;
	
	i = ft_strlen(s) - 1 ;
	j = 0;
	while (s[i]  && set[j])
	{
		if (set[j] == s[i])
		{
			i--;
			j = 0;
		}
		else 
			j++;
	}
	return (i);
}

char *ft_strtrim(char const *s1, char const *set)
{
	
	int i;
	int j;
	int size;
	char *final;
	char *str;
	char *str_set;
	str = ft_strdup(s1);
	str_set = ft_strdup(set);

	size = get_last_postion(str, str_set) - get_first_postion(str,str_set);
	final = malloc(sizeof(char) *  size + 1);
	if (final == NULL)
		return NULL;
	i = get_first_postion(str, str_set);
	j = 0;
	if (ft_strlen(ft_strdup(s1)) == i)
		return (ft_strdup(""));
	if (str == NULL)
		return NULL;
	while (i <= get_last_postion(str,str_set))
	{
		final[j] = str[i];
		i++;
		j++;
	} 
	final[j] = '\0';
	return (final);
}
