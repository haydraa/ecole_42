/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:50:27 by jghribi           #+#    #+#             */
/*   Updated: 2023/07/01 13:50:29 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_msg(char *str, t_data *data)
{
	write(2, "Minisheru: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": not a valid identifier\n", 25);
	data->data5.last_error = 1;
}

void	co_7(t_env_list *p_env_name, char *name, t_data *data, char *value)
{
	p_env_name = ft_search_env(data, name);
	if (!p_env_name)
		ft_env_lstadd_back(&data->env_table, ft_env_lstnew(name, value));
	else
	{
		free(p_env_name->value);
		free(name);
		p_env_name->value = ft_strdup(value);
		free(value);
	}
		data->data3.export_num = 0;
}

int	first_enter(char **arg, t_data *data)
{
	data->data3.export_num = 1;
	data->data4.f = 0;
	if (!arg[data->data4.f])
	{
		ft_sort_list(data);
		ft_display_env(data->env_table_sorted);
		return (1);
	}
	return (0);
}

int	con(char **arg, t_data *data, int key)
{
	if (key == 1)
	{
		if (arg[data->data4.f][data->data4.e])
				data->data4.e++;
		if (data->data3.export_num > 0)
			export_msg(arg[data->data4.f], data);
		return (1);
	}
	return (0);
}

int	continue_6(char **arg, t_data *data, int key)
{
	if (key == 0)
	{
		while (ft_isalnum(arg[data->data4.f][data->data4.e]) == 1 \
				|| arg[data->data4.f][data->data4.e] == '_')
		{
			data->data3.export_num++;
			data->data4.e++;
		}
		if ((arg[data->data4.f][data->data4.e] == '=' || arg[data->data4.f] \
				[data->data4.e] == '\0') && data->data4.e > 0)
		{
			if (ft_correct_env_name(arg, data) == 1)
				return (1);
		}
		else
		{
			return (1);
		}
		return (0);
	}
	return (con(arg, data, key));
}
