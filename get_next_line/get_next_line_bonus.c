#include "get_next_line_bonus.h"

/*----------------------------- look for the /n -----------------------------*/

int	ft_find_line(t_list *stash)
{
	int		i;
	t_list	*corrent;

	if (stash == NULL)
		return (0);
	corrent = ft_last(stash);
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

t_list	*ft_last(t_list *stash)
{
	t_list	*corrnet;

	corrnet = stash;
	while (corrnet && corrnet->next)
		corrnet = corrnet->next;
	return (corrnet);
}

char	*get_next_line(int fd)
{
	t_list	*stash = NULL;
	char			*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	/*----- read from fd and add to linked list ------*/
	ft_read_stock(fd, &stash);
	if (stash == NULL)
		return (NULL);
	/*------ extract from stach to line ------*/
	ft_get_line(stash, &line);
	/*---------- clean up stash -----------*/
	ft_clean(&stash);
	if (line[0] == '\0')
	{
		ft_free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
/*---------- extract all the from stash and put it line ---------------------*/

	/*------------------ stoping when we found '\n' ---------------------*/

void	ft_get_line(t_list *stash,char **line)
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
/*------------------- use read to add cararcter to stash --------------------*/

void	ft_read_stock(int fd, t_list **stach)
{
	char	*buff;
	int		reads;

	if (fd == -1)
		return ;
	reads = 1;
	while (!ft_find_line(*stach) && reads != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		reads = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stach == NULL && reads == 0) || reads == -1)
		{
			free(buff);
			return ;
		}
		buff[reads] = '\0';
		ft_add(stach, buff, reads);
		free(buff);
	}
}
/*
#include <stdio.h>

int main(void)
{
	int fd;
    int i;
	char **line[100];

    i = open("ft_txt",O_RDONLY);
    fd = open("ft_text.txt", O_RDONLY);
	while (1)
	{
		*line = get_next_line_bonus(fd);
        *line = get_next_line_bonus(i);
   		printf("%s", line);
		if (line == NULL)
			return -1;
		free(line);
	}
	return 0;
}*/
