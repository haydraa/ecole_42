/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:11 by cormiere          #+#    #+#             */
/*   Updated: 2023/07/01 14:55:06 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_intlen(int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len = 1;
	}
	nb = n;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				len;

	len = ft_intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	nb = n;
	while (nb > 0 && len >= 0)
	{
		str[len--] = '0' + nb % 10;
		nb = nb / 10;
	}
	return (str);
}

int	main_utils_2(t_data *data, int i)
{
	if (i == 3)
	{
		data->data3.main_error = 0;
		add_history(data->main_str);
		data->data5.last_error = 127;
		data->bsn = 1;
		return (1);
	}
	return (0);
}

void	close_hell(t_data *data)
{
	data->close_need = 1;
	data->data5.stdin_save = dup(1);
	data->data5.stdout_save = dup(0);
	data->data5.is_pipe = 0;
	data->data4.is_built_in = 0;
}

int	ft_atoi(const char *str)
{
	int			nbr;
	int			neg;
	long int	result;

	nbr = 0;
	neg = 1;
	result = 0;
	while ((str[nbr] >= 9 && str[nbr] <= 13) || str[nbr] == 32)
		nbr++;
	if (str[nbr] == '+' || str[nbr] == '-')
	{
		if (str[nbr] == '-')
			neg *= -1;
		nbr++;
	}
	while (str[nbr] >= 48 && str[nbr] <= 57)
	{
		if (result * 10 + (str[nbr] - 48) < result)
			return (-2);
		result = result * 10 + (str[nbr] - 48);
		nbr++;
	}
	return ((result * neg));
}
