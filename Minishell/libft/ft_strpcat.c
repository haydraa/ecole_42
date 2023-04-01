/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:36:08 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 18:13:16 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpcat(char *s1, const char *s2, size_t n, size_t pos)
{
	size_t	j;

	j = 0;
	while (j < n)
	{
		s1[pos + j] = s2[j];
		j++;
	}
	return (s1);
}
