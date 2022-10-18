#include "get_next_line.h"


int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void generate_line(char **line, t_list *stash)
{
	int i;
	int len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}
// this fun goin to clean waht i have used and leave the rest
void clean_stash(t_list **stash)
{
	t_list *last;
	t_list *clean_node;
	int i;
	int j;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last ->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last ->content) -i) +1));
	if (clean_node->content == NULL)
		return;
	j = 0;
	while (last -> content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}
				/* free the entire stash */
void free_stash(t_list *stash)
{
	t_list *corrent;
	t_list *next;

	corrent = stash;
	while(corrent)
	{
		free(corrent->content);
		next = corrent->next;
		free(corrent);
		corrent = next;
	}
}
// adds the content of our buffer to the end of stash
void	add_to_stash(t_list **stash, char *buff, int readed)
{
	int i;
	t_list *last;
	t_list *new_node;
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * readed +1);
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buff[i] && i < readed)
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
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}