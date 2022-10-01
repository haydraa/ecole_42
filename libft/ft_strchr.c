/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:54:10 by jghribi           #+#    #+#             */
/*   Updated: 2022/09/30 18:54:25 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(char *str, int c)
{
	int i;
	
	i = 0;
	
	
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return &str[i];
		i++;
	}
	if (c == '\0')
		return &str[i];
	return (0);
}