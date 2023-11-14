/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:58:09 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/14 14:02:02 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_map_utils(char **map, int i, int j, int *dir_player)
{
	if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		return (-1);
	if (map[i][j] == ' ')
	{
		if (i - 1 == 0 && map[i + 1] != NULL)
		{
			if (map[i + 1][j] != '1' && map[i + 1][j] != ' ')
				return (-1);
		}
		else if (i - 1 != 0 && map[i + 1] != NULL)
		{
			if (map[i + 1][j] != '1' && map[i + 1][j] != ' ')
				return (-1);
			else if (map[i - 1][j] != '1' && map[i - 1][j] != ' ')
				return (-1);
		}
	}
	else if (map[i][j] != '1' && map[i][j] != '2' && map[i][j] != '0'
			&& map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'S'
			&& map[i][j] != 'W' && map[i][j] != ' ')
		return (-2);
	if (map[i][j] == 'E' || map[i][j] == 'S'
			|| map[i][j] == 'W' || map[i][j] == 'N')
		(*dir_player)++;
	return (0);
}

int	check_map_utils2(char **map, int i, int j, int *dir_player)
{
	int	ret;
	int	len;

	len = 0;
	while (map[len])
		len++;
	while (map[i][j])
	{
		if (i == 0 || i == len - 1)
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
				return (-1);
		}
		else if (i != 0)
		{
			ret = check_map_utils(map, i, j, dir_player);
			if (ret < 0)
				return (ret);
		}
		j++;
	}
	return (0);
}

int	check_map(char **map)
{
	int	i;
	int	j;
	int	dir_player;
	int	len;
	int	ret;

	len = 0;
	while (map[len])
		len++;
	dir_player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		ret = check_map_utils2(map, i, j, &dir_player);
		if (ret < 0)
			return (ret);
		i++;
	}
	if (dir_player < 1 || dir_player > 1)
		return (-3);
	return (0);
}

int	check_map2_utils(char **map, int len, int len2, int i)
{
	int	j;

	j = 0;
	if (len < len2)
	{
		while (j < len2)
		{
			if (j >= len)
				if (map[i + 1][j] != '1')
					return (-1);
			j++;
		}
	}
	else if (len > len2 && i != 0)
	{
		while (j < len)
		{
			if (j >= len)
				if (map[i][j] != '1')
					return (-1);
			j++;
		}
	}
	return (0);
}

int	check_map2(char **map)
{
	int	i;
	int	j;
	int	len;
	int	len2;

	i = 0;
	while (map[i])
	{
		if (map[i + 1] != NULL)
		{
			j = 0;
			len = ft_strlen(map[i]);
			len2 = ft_strlen(map[i + 1]);
			if (len != len2)
				if (check_map2_utils(map, len, len2, i) == -1)
					return (-1);
		}
		i++;
	}
	return (0);
}
