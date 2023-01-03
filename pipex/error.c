#include "pipex.h"

void ft_error(t_data *data,char *cmd)
{
			write(2,"bash: " ,6);
			write(2, cmd , ft_strlen(cmd));
			write(2, ": command not found\n", 20);
			ft_free(data->path_tab);
			exit(EXIT_FAILURE);
}

void ft_free(char **tab)
{
		int i;
		int j;
		
		i = 0;
		j = 0;
		while (tab[i])
				i++;
		while (j < i)
		{
				free(tab[j]);
				j++;
		}
		free(tab);
}
