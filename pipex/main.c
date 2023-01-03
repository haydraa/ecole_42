/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:33:34 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/03 17:33:43 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_path(t_data *data, char **argv, char **envp)
{
	int i;
	
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=",5) == 0)
		{
			data->path = envp[i] + 5;
			break ;
		}
		i++;	
	}
	data->path_tab = ft_split(data->path,':');
}

char *check_cmd(char *cmd, t_data *data)
{
	char *slash;
	char *path_ac;
	int i;
	
	i = -1;
	if(ft_strlen(cmd) == 0)
			ft_error(data,cmd);
	if (ft_strnstr(cmd, "/",ft_strlen(cmd)))
					return (cmd);
	data->cmd1 = ft_split(cmd, ' ');
	while (data->path_tab[++i])
	{
		slash = ft_strjoin(data->path_tab[i], "/");
		path_ac = ft_strjoin(slash,data->cmd1[0]);
		free(slash);
		if (!(access(path_ac, F_OK)))
		{
				ft_free(data->cmd1);
				return path_ac;
		}
		free(path_ac);
	}
	ft_free(data->cmd1);
	return (NULL);					
}

int main(int argc,char **argv, char **envp)
{
	t_data data;
	data.infile = open(argv[1], O_RDONLY);
	if (data.infile == -1)
		return 0;
	data.outfile = open(argv[argc -1], O_RDWR | O_TRUNC | O_CREAT);
	if (data.outfile == -1)
		return 0;
	ft_path(&data,argv,envp);
	pipex(&data,argv ,envp);
	close(data.infile);
	close(data.outfile);
	ft_free(data.path_tab);
	return 0;
}
