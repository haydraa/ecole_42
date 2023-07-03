/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:45:35 by jghribi           #+#    #+#             */
/*   Updated: 2023/07/01 11:46:46 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_child(t_data *data)
{
	int	i;

	i = -1;
	while (data->data1.paths[++i])
		free(data->data1.paths[i]);
	free(data->data1.paths);
	i = -1;
	if (data->data1.here == 1)
		ft_lstclear(data, &data->cmd_table);
	while (data->data4.redir_file[++i])
		free(data->data4.redir_file[i]);
	free(data->data4.redir_file);
	free(data->data4.redir_type);
	free(data->cmd_table);
	if (data->data3.pcommand != NULL)
		free(data->data3.pcommand);
	ft_env_lstclear(&data->env_table);
	ft_env_lstclear(&data->env_table_sorted);
	free(g_data->data3.file);
	close(g_data->data3.fd);
	ft_close_for_fun();
}

char	*create_here_doc_file(t_data *data)
{
	char	*file;
	char	character;

	character = (char)(data->data1.here_doc_nbr + 97);
	file = ft_strjoin_c("/tmp/.here_doc", character);
	return (file);
}

void	here(t_data *data)
{
	free(data->data3.file);
	data->data3.file = NULL;
	close(data->data3.fd);
}
