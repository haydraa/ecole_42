/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:21:32 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/02 16:03:22 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_data	*g_data;

void	sigint_handler_parent(int sig)
{
	(void)sig;
	printf("\n");
}

void	sigint_handler_child(int sig)
{
	if (sig == SIGINT)
	{
		free_child(g_data);
		exit(6);
	}
}

static char	*read_user_input(void)
{
	char	*str2;

	str2 = readline("> ");
	if (str2 == NULL)
	{
		printf("warning: here-document at line 1 ");
		printf("delimited by end-of-file (wanted `EOF')\n");
	}
	return (str2);
}

void	child_process(t_data *data, char *str)
{
	char	*str2;

	str2 = NULL;
	signal(SIGINT, sigint_handler_child);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		str2 = read_user_input();
		if (str2 == NULL)
		{
			free(str2);
			free_child(data);
			exit(0);
		}
		str2 = ft_search_and_change_env_var(data, str2);
		if (str_diff(str, str2) == 0)
		{
			free(str2);
			free_child(data);
			exit(0);
		}
		write(data->data3.fd, str2, ft_strlen(str2));
		write(data->data3.fd, "\n", 1);
		free(str2);
	}
}

int	here_doc_fct(t_data *data, char *str)
{
	g_data = data;
	data->data3.file = create_here_doc_file(data);
	data->data3.fd = open(data->data3.file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	data->data2.pid = fork();
	if (data->data2.pid == 0)
		child_process(data, str);
	else if (data->data2.pid > 0)
	{
		signal(SIGINT, sigint_handler_parent);
		wait(&data->data2.pid);
		if (WIFEXITED(data->data2.pid))
		{
			data->data2.exit_s = WEXITSTATUS(data->data2.pid);
			if (data->data2.exit_s == 6)
			{
				data->data5.last_error = 130;
				return (6);
			}
			else
				here(data);
		}
	}
	return (0);
}
