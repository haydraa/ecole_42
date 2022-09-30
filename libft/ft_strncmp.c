/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:48:11 by jghribi           #+#    #+#             */
/*   Updated: 2022/09/30 20:16:52 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	unsigned char *s = (unsigned char*) s1;
	unsigned char *str = (unsigned char*) s2;	
	i = 0;
	while (i < n && (s[i] || str[i]))
	{
		if (s[i] != str[i])
			return (s[i] - str[i]);
		i++;
	}
	return 0;
}
