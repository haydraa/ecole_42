/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lite_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <jghribi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:59:58 by jghribi           #+#    #+#             */
/*   Updated: 2023/11/18 18:46:06 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_cub(char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(str, '.');
	while (tmp[i])
		i++;
	if (ft_strcmp(tmp[i - 1], "cub") != 0)
	{
		printf("ERROR: WRONG FILE .FORMAT\n");
		free_tab(tmp);
		exit(1);
	}
	free_tab(tmp);
}

void	check_xpm(char *path, t_cub3D *data)
{
	char	**tmp;
	char	*trim;
	int		i;

	i = 0;
	trim = ft_strtrim(path, "\n");
	tmp = ft_split(trim, '.');
	while (tmp[i])
		i++;
	if (i == 0 || ft_strcmp(tmp[i - 1], "xpm") != 0)
	{
		printf("ERROR: WRONG TEXTURE FILE .FORMAT\n");
		free_tab(tmp);
		free(trim);
		the_ultimate_free(data);
	}
	free(trim);
	free_tab(tmp);
}

int	check_color(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (ft_isdigit(color[i]) == 0)
			return (-1);
		i++;
	}
	if (i == 0)
		return (-1);
	return (0);
}

void	free_function(t_cub3D *data)
{
	printf("ERROR: THERE ARE A WRONG COLOR\n");
	the_ultimate_free(data);
}

void	check_colors2(t_cub3D *data)
{
	int	len;
	int	len2;
	int	i;

	i = 0;
	len2 = 0;
	len = 0;
	while (data->texture.c_color[len2])
		len2++;
	while (data->texture.f_color[len])
		len++;
	if (len < 3 || len < 3)
		free_function(data);
	while (data->texture.c_color[i] || data->texture.f_color[i])
	{
		if (data->texture.c_color[i] != NULL)
			if (check_color(data->texture.c_color[i]) == -1)
				free_function(data);
		if (data->texture.f_color[i] != NULL)
			if (check_color(data->texture.f_color[i]) == -1)
				free_function(data);
		i++;
	}
}
