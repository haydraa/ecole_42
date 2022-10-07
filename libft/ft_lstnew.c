/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:45:57 by jghribi           #+#    #+#             */
/*   Updated: 2022/10/07 11:46:24 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*the_new_node;

	the_new_node = ft_calloc(sizeof(t_list), 1);
	if (the_new_node == NULL)
		return (NULL);
	the_new_node->content = content;
	the_new_node->next = NULL;
	return (the_new_node);
}
