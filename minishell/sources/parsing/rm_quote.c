/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:32 by cormiere          #+#    #+#             */
/*   Updated: 2023/06/07 14:11:59 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**rm_quote(char **tabl, t_data *data)
{
	data->data2.i = 0;
	data->data2.j = 0;
	data->data5.str_f = NULL;
	data->data1.dquote = 0;
	data->data1.squote = 0;
	while (tabl[data->data2.j])
	{
		data->data2.i = 0;
		data->data5.str_f = malloc(sizeof(char)
				* (ft_strlen(tabl[data->data2.j]) + 1));
		if (!data->data5.str_f)
			exit(EXIT_FAILURE);
		data->data5.str_f[ft_strlen(tabl[data->data2.j])] = '\0';
		data->data2.x = 0;
		data->data2.nbr = 0;
		while (tabl[data->data2.j][data->data2.i])
			data->data5.str_f = rm_quote2(data, tabl, data->data5.str_f);
		data->data5.str_f[ft_strlen(tabl[data->data2.j])
			- data->data2.nbr] = '\0';
		free(tabl[data->data2.j]);
		tabl[data->data2.j] = data->data5.str_f;
		data->data2.j = data->data2.j + 1;
	}
	return (tabl);
}

char	*rm_quote2(t_data *data, char **tabl, char *str)
{
	quotes_switch(data, tabl[data->data2.j], data->data2.i);
	if (tabl[data->data2.j][data->data2.i] == '"' && data->data1.squote == 0)
		data->data2.nbr++;
	else if (tabl[data->data2.j][data->data2.i] == '\''
		&& data->data1.dquote == 0)
		data->data2.nbr++;
	else
	{
		str[data->data2.x] = tabl[data->data2.j][data->data2.i];
		data->data2.x = data->data2.x + 1;
	}
	data->data2.i = data->data2.i + 1;
	return (str);
}

int	ft_is_builtin(t_data *data, const char *s1)
{
	if (ft_strncmp(s1, "pwd") == 0)
		return (0);
	if (ft_strncmp(s1, "env") == 0)
	{
		data->data2.close_l = 1;
		return (0);
	}
	if (ft_strncmp(s1, "cd") == 0)
		return (0);
	if (ft_strncmp(s1, "echo") == 0)
		return (0);
	if (ft_strncmp(s1, "export") == 0)
	{
		data->data2.close_l = 1;
		return (0);
	}
	if (ft_strncmp(s1, "unset") == 0)
		return (0);
	if (ft_strncmp(s1, "exit") == 0)
		return (0);
	return (1);
}

char	*ft_found_path(t_data *data, char *str)
{
	t_env_list	*env_list;

	env_list = data->env_table;
	while (env_list)
	{
		if (ft_strncmp(str, env_list->name) == 0)
			return (ft_malloc_str(env_list->value));
		env_list = env_list->next;
	}
	return (ft_malloc_str(""));
}
