/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:37:49 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/02 15:36:26 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	bin_export(char **arg, t_data *data)
{
	int	i;

	if (first_enter(arg, data) == 1)
		return ;
	while (arg[data->data4.f])
	{
		data->data4.e = 0;
		while (arg[data->data4.f][data->data4.e])
		{
			if (arg[data->data4.f][data->data4.e] == '_' \
				&& data->data4.e == 0)
				break ;
			i = continue_6(arg, data, 0);
			if (i == 1)
				ft_wrong_env_name(arg, data);
			continue_6(arg, data, 1);
		}
		data->data4.f++;
	}
}

void	ft_display_env(t_env_list *list)
{
	t_env_list	*begin;

	begin = list;
	while (begin)
	{
		if (begin->name[0] == '_')
			begin = begin->next;
		else
		{
			printf("declare -x %s", begin->name);
			if (begin->value)
				printf("=\"%s\"\n", begin->value);
			else
				printf("\n");
			begin = begin->next;
		}
	}
}

t_env_list	*ft_search_env(t_data *data, char *name)
{
	t_env_list	*current_elmt;

	current_elmt = data->env_table;
	while (current_elmt)
	{
		if (ft_strncmp(name, current_elmt->name) == 0)
			return (current_elmt);
		current_elmt = current_elmt->next;
	}
	return (NULL);
}

int	ft_correct_env_name(char **arg, t_data *data)
{
	t_env_list	*p_env_name;

	p_env_name = NULL;
	data->data4.name = ft_substr(arg[data->data4.f], 0, data->data4.e);
	if (arg[data->data4.f][data->data4.e] == '=' &&
		arg[data->data4.f][data->data4.e + 1])
		data->data4.value = ft_substr(arg[data->data4.f], data->data4.e + 1, \
			ft_strlen(arg[data->data4.f]) - (data->data4.e + 1));
	if (arg[data->data4.f][data->data4.e] == '=' &&
		arg[data->data4.f][data->data4.e + 1])
		data->data4.e = ft_strlen(arg[data->data4.f]);
	else
		data->data4.value = NULL;
	if (data->data4.value == NULL)
	{
		if (ft_isdigit(data->data4.name[0]) == 1)
		{
			data->data3.export_num = 0;
			free(data->data4.name);
			return (1);
		}
	}
	co_7(p_env_name, data->data4.name, data, data->data4.value);
	return (0);
}

void	ft_wrong_env_name(char **arg, t_data *data)
{
	char	*name;

	while (arg[data->data4.f][data->data4.e] &&
		arg[data->data4.f][data->data4.e] != ' ')
		data->data4.e++;
	name = ft_substr(arg[data->data4.f], 0, data->data4.e);
	write(2, "Minisheru: ", 11);
	write(2, name, ft_strlen(name));
	write(2, ": not a valid identifier\n", 25);
	data->data5.last_error = 1;
	data->data3.export_num = 0;
	free(name);
}
