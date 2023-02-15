/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:04:35 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/14 18:57:28 by jghribi          ###   ########.fr       */
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

void	ft_create_line(char **line, t_gnl *stash)
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
	*line = malloc(sizeof(char) * (len + 1));
}

void	ft_clean(t_gnl **stash)
{
	t_gnl	*last;
	t_gnl	*cln;

	cln = malloc(sizeof(t_gnl));
	if (stash == NULL || cln == NULL)
		return ;
	cln->next = NULL;
	last = ft_to_end(*stash);
	cln->i = 0;
	while (last->content[cln->i] && last ->content[cln->i] != '\n')
		cln->i++;
	if (last->content && last->content[cln->i] == '\n')
		cln->i++;
	cln->content = malloc(sizeof(char) * ((len(last->content) - cln->i) + 1));
	if (cln->content == NULL)
		return ;
	cln->j = 0;
	while (last -> content[cln->i])
		cln->content[cln->j++] = last->content[cln->i++];
	cln->content[cln->j] = '\0';
	ft_free_gnl(*stash);
	*stash = cln;
	free(cln->content);
	free(cln);
}

void	ft_free_gnl(t_gnl *stash)
{
	t_gnl	*corrent;
	t_gnl	*next;

	corrent = stash;
	while (corrent)
	{
		free(corrent->content);
		next = corrent->next;
		free(corrent);
		corrent = next;
	}
}

void	ft_add(t_gnl **stash, char *buff, int buffer)
{
	int		i;
	t_gnl	*last;
	t_gnl	*new_node;

	new_node = malloc(sizeof(t_gnl));
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

/*int main()
{
	char *line;

	line = get_next_line(0);
	//printf("%s\n",line);
	free(line);
	line = get_next_line(0);
	//printf("%s\n",line);
	free(line);
	line = get_next_line(0);
	//printf("%s\n",line);
	free(line);
	line = get_next_line(0);
	//printf("%s\n",line);
	free(line);
	line = get_next_line(0);
	free(line);
}*/
