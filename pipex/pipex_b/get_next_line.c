/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:01:58 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/14 18:56:01 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_line(t_gnl *stash)
{
	int		i;
	t_gnl	*corrent;

	if (stash == NULL)
		return (0);
	corrent = ft_to_end(stash);
	i = 0;
	while (corrent->content[i])
	{
		if (corrent->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_gnl	*ft_to_end(t_gnl *stash)
{
	t_gnl	*corrnet;

	corrnet = stash;
	while (corrnet && corrnet->next)
		corrnet = corrnet->next;
	return (corrnet);
}

void	ft_get_line(t_gnl *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	ft_create_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash ->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

char	*get_next_line(int fd)
{
	t_gnl	*stash;
	char	*line;

	stash = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	ft_read_stock(fd, &stash);
	if (stash == NULL)
		return (NULL);
	ft_get_line(stash, &line);
	ft_clean(&stash);
	if (line && line[0] == '\0')
	{
		ft_free_gnl(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_read_stock(int fd, t_gnl **stach)
{
	char	*buff;
	int		reads;
	int		buffer;

	buffer = BUFFER_SIZE;
	if (fd == -1)
		return ;
	reads = 1;
	while (!ft_find_line(*stach) && reads != 0)
	{
		buff = malloc(sizeof(char) * (buffer + 1));
		if (buff == NULL)
			return ;
		reads = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stach == NULL && reads == 0) || reads == -1)
		{
			free(buff);
			return ;
		}
		buff[reads] = '\0';
		ft_add(stach, buff, buffer);
		free(buff);
	}
}
