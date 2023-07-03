/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:14 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/01 16:54:29 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handler(int sigtype)
{
	if (sigtype == SIGINT)
	{
		g_data->sigint = 1;
		printf("^C\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler2(int sigtype)
{
	if (sigtype == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
	if (sigtype == SIGQUIT)
	{
		printf("Quit (core dumped)\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	main_fonction_two(t_data *data)
{
	data->data1.paths = recup_path(data);
	init_main(data);
	setup_term(0);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	data->main_str = readline("Minisheru > ");
	if (main_utils(data) == 1)
		return ;
	if (g_data->sigint)
	{
		g_data->sigint = 0;
		data->data5.last_error = 130;
	}
	data->cmd_table = ft_lstnew(NULL, NULL, NULL);
	setup_term(1);
	if (!data->main_str)
		bin_exit(data, 0);
	if (str_is_empty(data->main_str) != 0)
		add_history(data->main_str);
	data->data3.main_error = parserror(ft_lexer(data->main_str, data), data);
}

void	run_main_loop(t_data *data, char **env)
{
	while (1)
	{
		rl_done = 0;
		data->str_exit = 0;
		data->data2.close_l = 0;
		main_fonction_two(data);
		if (data->data3.main_error == 0 && data->bsn == 0)
		{
			data->cmd_table_temp = data->cmd_table;
			data->cmd_table = data->cmd_table->next;
			signal(SIGINT, handler2);
			signal(SIGQUIT, handler2);
			parserror(ft_env_var(data), data);
			exekerror(ft_execution(data, env), data);
		}
		ft_free_all(data);
		if (data->data3.main_error != -1)
			ft_lstclear(data, &data->cmd_table_temp);
		else
			free(data->cmd_table);
	}
}

//t_data *g_data;

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (!*env)
	{
		dprintf(2, "env not found\n");
		exit(1);
	}
	if (argc != 1 || !(argv[0]))
		exit(0);
	g_data = &data;
	g_data->sigint = 0;
	data.close_need = 0;
	data.data5.lol = 0;
	data.data5.last_error = 0;
	data.data2.lst_nbr = 0;
	data.data2.rdj = 0;
	data.data5.finale = 0;
	data.data4.sit = 0;
	data.data4.fds_malloced = 0;
	parserror(ft_put_env_in_lst(&data, env), &data);
	data.data5.str_f = NULL;
	data.env_table_sorted = NULL;
	run_main_loop(&data, env);
	return (0);
}
