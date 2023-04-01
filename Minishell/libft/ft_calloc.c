/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:56:46 by cormiere          #+#    #+#             */
/*   Updated: 2022/11/23 21:02:35 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		sizes;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size / nmemb != size)
		return (0);
	sizes = size * nmemb;
	ptr = malloc(sizes);
	if (!ptr)
		return (0);
	ft_bzero(ptr, sizes);
	return (ptr);
}
