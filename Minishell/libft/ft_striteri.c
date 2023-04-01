/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:34:19 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 16:34:20 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int				i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(n, &s[i]);
			i++;
			n++;
		}
	}
}
