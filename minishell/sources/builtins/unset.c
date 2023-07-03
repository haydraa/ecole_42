/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:40 by cormiere          #+#    #+#             */
/*   Updated: 2023/06/27 10:57:29 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	bin_unset(char **arg, t_data *data)
{
	data->data5.last_error = 0;
	data->data4.f = 0;
	while (arg[data->data4.f])
	{
		data->data4.e = 0;
		while (arg[data->data4.f][data->data4. e])
		{
			while (ft_isalnum(arg[data->data4.f][data->data4.e]) == 1 \
				|| arg[data->data4.f][data->data4.e] == '_')
				data->data4.e++;
			if (arg[data->data4.f][data->data4.e] == '\0')
				ft_remove_env_var(arg, data);
			else
				ft_name_error(arg, data);
			if (arg[data->data4.f][data->data4.e])
				data->data4.e++;
		}
		data->data4.f++;
	}
}

t_env_list	*ft_search_preenv(t_data *data, char *name)
{
	t_env_list	*current_elmt;

	current_elmt = data->env_table;
	if (current_elmt && !current_elmt->next)
		if (ft_strncmp(name, current_elmt->name) == 0)
			return (current_elmt);
	while (current_elmt && current_elmt->next)
	{
		if (ft_strncmp(name, current_elmt->next->name) == 0)
			return (current_elmt);
		current_elmt = current_elmt->next;
	}
	return (NULL);
}

void	ft_remove_env_var(char **arg, t_data *data)
{
	char		*name;

	name = ft_substr(arg[data->data4.f], 0, data->data4.e);
	if (ft_strncmp(name, "PATH") == 0)
		data->data4.unset = 1;
	if (ft_isdigit(name[0]) == 1)
	{
		write(2, "Minisheru: ", 11);
		write(2, arg[data->data4.f],
			ft_strlen(arg[data->data4.f]));
		write(2, ": not a valid identifier\n", 25);
		data->data3.export_num = 0;
		free(name);
		return ;
	}
	if (ft_strncmp(name, data->env_table->name) == 0 && data->env_table->next)
	{
		ft_clear_first_elmt(data);
		free(name);
	}
	else
		ft_clear_elmt(data, name);
}

void	ft_name_error(char **arg, t_data *data)
{
	char	*name;

	while (arg[data->data4.f][data->data4.e] &&
			arg[data->data4.f][data->data4.e] != ' ')
		data->data4.e++;
	name = ft_substr(arg[data->data4.f], 0, data->data4.e);
	printf("minishell: unset: `%s': not a valid identifier\n", name);
	data->data5.last_error = 1;
	free(name);
}
