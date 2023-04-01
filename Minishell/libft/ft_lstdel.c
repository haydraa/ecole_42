/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:30:09 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 18:06:45 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*buf;

	if (alst && *alst)
	{
		buf = *alst;
		while (buf)
		{
			tmp = buf->next;
			del(buf->content, buf->content_size);
			free(buf);
			buf = tmp;
		}
		*alst = NULL;
	}
}
