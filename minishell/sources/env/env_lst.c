/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_in_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:36:35 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/23 13:21:02 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_put_env_in_lst(t_data *data, char **env)
{
	int		i;
	int		pos;
	char	*name;
	char	*value;

	i = 0;
	data->env_table = NULL;
	while (env[i])
	{
		pos = 0;
		while (env[i][pos] && env[i][pos] != '=')
			pos++;
		name = ft_substr(env[i], 0, pos);
		value = ft_substr(env[i], pos + 1, ft_strlen(env[i]) - (size_t)pos);
		if (!name || !value)
			return (-3);
		ft_env_lstadd_back(&data->env_table, ft_env_lstnew(name, value));
		i++;
	}
	return (0);
}

void	ft_sort_list(t_data *data)
{
	if (data->env_table_sorted)
		ft_env_lstclear(&data->env_table_sorted);
	data->env_table_sorted = ft_dup_list(data->env_table);
	ft_insertion_sort(data);
}

t_env_list	*ft_dup_list(t_env_list *list)
{
	t_env_list	*elemt;
	t_env_list	*new_list;
	char		*name;
	char		*value;

	elemt = list;
	new_list = NULL;
	while (elemt)
	{
		name = ft_strdup(elemt->name);
		if (!name)
			return (NULL);
		if (elemt->value)
		{
			value = ft_strdup(elemt->value);
			if (!value)
				return (NULL);
		}
		else
			value = NULL;
		ft_env_lstadd_back(&new_list, ft_env_lstnew(name, value));
		elemt = elemt->next;
	}
	return (new_list);
}

void	ft_insertion_sort(t_data *data)
{
	t_env_list	*start;
	t_env_list	*analyse;
	t_env_list	*min;
	char		*tmp_name;
	char		*tmp_value;

	start = data->env_table_sorted;
	while (start && start->next)
	{
		min = start;
		analyse = start->next;
		while (analyse)
		{
			if (ft_strncmp(min->name, analyse->name) > 0)
				min = analyse;
			analyse = analyse->next;
		}
		tmp_name = start->name;
		tmp_value = start->value;
		start->name = min->name;
		start->value = min->value;
		min->name = tmp_name;
		min->value = tmp_value;
		start = start->next;
	}
}
