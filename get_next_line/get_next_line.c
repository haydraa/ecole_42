#include "get_next_line.h"

/*----------------------------- look for the /n -----------------------------*/

int	found_line(t_list *stash)
{
	int		i;
	t_list	*corrent;

	if (stash == NULL)
		return (0);
	corrent = ft_lst_get_last(stash);
	i = 0;
	while (corrent->content[i])
	{
		if (corrent->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
/*---------------- get last nood ----------*/

t_list	*ft_lst_get_last(t_list *stash)
{
	t_list	*corrnet;

	corrnet = stash;
	while (corrnet && corrnet->next)
		corrnet = corrnet->next;
	return (corrnet);
}

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	/*----- read from fd and add to linked list ------*/
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	/*------ extract from stach to line ------*/
	extract_line(stash, &line);
	/*---------- clean up stash -----------*/
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
/*---------- extract all the from stash and put it line ---------------------*/

	/*------------------ stoping when we found '\n' ---------------------*/

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
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
/*------------------- use read to add cararcter to stash --------------------*/

void	read_and_stash(int fd, t_list **stach)
{
	char	*buff;
	int		readed;

	if (fd == -1)
		return ;
	readed = 1;
	while (!found_line(*stach) && readed != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stach == NULL && readed == 0) || readed == -1)
		{
			free(buff);
			return ;
		}
		buff[readed] = '\0';
		add_to_stash(stach, buff, readed);
		free(buff);
	}
}

#include <stdio.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("ft_text.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			return -1;
		free(line);
	}
	return 0;
}
