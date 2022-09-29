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

int get_first_postion(char const *s, char const *set)
{
	int i;
	i = 0;
	while (i == set)
		i++;
	return (i);
}

int get_last_postion(char const *s, char const *set)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i == set)
		i--;
	return (i);
}

char *ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;
	int size;
	char *final;

	size = get_last_postion(s1, set) - get_first_postion(s1, set);
	final = malloc(sizeof(char) *  size + 1);
	i = get_first_postion(s1,set);
	if (s1[0] == NULL)
		return NULL;
	while (s1[i] <= get_last_postion(s1,set))
	{
		final[j] = s1[i];
		i++;
		j++;
	} 
	return (final);
}

int main()
{
	char s[] = "   lpocc    ";
	char d[] = ' ';
	char *dest ;
	dest = ft_strtrim(s,d);
	printf("%s\n", dest);
	free(dest);
	return 0;
	
}