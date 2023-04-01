/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:30:30 by cormiere          #+#    #+#             */
/*   Updated: 2022/12/07 16:48:59 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*buf;

	if (f && lst)
	{
		buf = f(lst);
		tmp = buf;
		lst = lst->next;
		while (lst)
		{
			tmp->next = f(lst);
			lst = lst->next;
			tmp = tmp->next;
		}
		return (buf);
	}
	return (NULL);
}
