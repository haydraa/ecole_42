/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_replace_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:37:04 by cormiere          #+#    #+#             */
/*   Updated: 2023/05/25 09:59:20 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_search_and_change_env_var(t_data *data, char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (str);
	if (data == NULL || str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) == 1 \
			|| str[i + 1] == '_') && data->data1.squote == 0)
		{
			str = ft_change_var_env(str, i, data);
			if (i > 0)
				i--;
		}
		i++;
	}
	return (str);
}

char	*ft_change_var_env(char *str, int pos, t_data *data)
{
	int		len;
	int		i;
	char	*value;

	len = 0;
	i = pos;
	if (str[pos + 1] == '0')
		str = ft_replace_word(str, pos, 2, "minishell");
	else
	{
		while (ft_isalnum(str[i + 1]) == 1 \
			|| str[i + 1] == '_')
		{
			len++;
			i++;
		}
		value = ft_is_var_env(data, str, pos, len);
		str = ft_replace_word(str, pos, len + 1, value);
	}
	return (str);
}
