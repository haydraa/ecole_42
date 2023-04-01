/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:36:41 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 16:36:42 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s)
		return (NULL);
	if (!*s)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = ft_strlen(s) - 1;
	if (!s[i])
		return (ft_strdup(""));
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	str = ft_strnew(j - i + 1);
	if (!str)
		return (NULL);
	k = 0;
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
