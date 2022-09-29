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
	j = i;
	while (set[j] == s[i])
	{
		i++;
		j++;
	}
	printf("%d\n", i);
	return (i);
}

int get_last_postion(char *s, char  *set)
{
	int i;
	int j;

	i = ft_strlen(s);
	j = i;
	while (set[j] == s[i])
	{
		i--;
		j--;
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

	size = get_last_postion(str, str_set) - 
		get_first_postion(str,str_set);
	final = malloc(sizeof(char) *  size + 1);
	i = get_first_postion(str, str_set);
	if (str == NULL)
		return NULL;
	while (str[i] <= get_last_postion(str,str_set))
	{
		final[j] = str[i];
		i++;
		j++;
	} 
	return (final);
}

int main()
{
	char s[] = " n  nlpocc   ";
	char d[] = " ";
	char *dest ;
	dest = ft_strtrim(s,d);
	printf("%s\n", dest);
	free(dest);
	return 0;
	
}
