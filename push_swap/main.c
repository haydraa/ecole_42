/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:21:44 by jghribi           #+#    #+#             */
/*   Updated: 2023/01/14 11:21:45 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

int	len_node(t_node **list)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *list;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	get_min_max(int len, t_node **a, t_data *data)
{
	int		i;
	t_node	*temp;
	int		pos1;
	int		pos2;

	temp = *a;
	pos1 = find_big(a);
	pos2 = find_small(a, len);
	while (pos1--)
		temp = temp->next;
	data->max = temp->data;
	temp = *a;
	while (pos2--)
		temp = temp->next;
	data->min = temp->data;
}

void	start(int len, t_data *data)
{
	t_node	**a;

	a = send_to_a(len, data);
	get_min_max(len, a, data);
	to_algo(a, data);
	ft_free(data->all_final);
	free_node(a);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		x;

	x = 0;
	if (argc == 1)
		return (0);
	data.final = join(argc, argv);
	data.final_trim = ft_strtrim(data.final, " ");
	free(data.final);
	if (ft_check_arg(data.final_trim) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	data.all_final = ft_split(data.final_trim, ' ');
	free(data.final_trim);
	while (data.all_final[x])
		x++;
	if (to_dob(data.all_final) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	start(x, &data);
	return (0);
}
