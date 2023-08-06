/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:04:35 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/06 16:30:22 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_create_line(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 100));
}

void	ft_clean(t_list **stash)
{
	t_list	*last;
	t_list	*cleann;
	int		i;
	int		j;

	cleann = malloc(sizeof(t_list));
	if (stash == NULL || cleann == NULL)
		return ;
	cleann->next = NULL;
	last = ft_to_end(*stash);
	i = 0;
	while (last->content[i] && last ->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	cleann->content = malloc(sizeof(char) * ((len(last->content) - i) + 1));
	if (cleann->content == NULL)
		return ;
	j = 0;
	while (last -> content[i])
		cleann->content[j++] = last->content[i++];
	cleann->content[j] = '\0';
	ft_free(*stash);
	*stash = cleann;
}

void	ft_free(t_list *stash)
{
	t_list	*corrent;
	t_list	*next;

	corrent = stash;
	while (corrent)
	{
		free(corrent->content);
		next = corrent->next;
		free(corrent);
		corrent = next;
	}
}

void	ft_add(t_list **stash, char *buff, int buffer)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * buffer +1);
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buff[i] && i < buffer)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = ft_to_end(*stash);
	last->next = new_node;
}
