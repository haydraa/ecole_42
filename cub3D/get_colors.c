#include "cub3D.h"

int	ft_count(char **tmp, int x)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	if ((i <= 3 || i > 4) && x != 1)
		return (-1);
	return (i);
}

void	fill_tab(char **tmp, char **color)
{
	int	i;

	i = -1;
	while (tmp[++i])
	{
		if (stupid_check(tmp[i]))
			color[i] = ft_strdup("");
		else
			color[i] = ft_strtrim(tmp[i], " ");
	}
	color[i--] = NULL;
}

void	get_color_c(t_cub3D *data, char *line)
{
	char	*temp;
	char	*temp2;
	char	**tmp;
	int		i;

	temp = ft_strtrim(line, "\n");
	temp2 = ft_strtrim(temp, " ");
	free(temp);
	temp = ft_strtrim(temp2, "\t");
	free(temp2);
	temp2 = ft_strtrim(temp, "C");
	tmp = ft_split(temp2, ',');
	i = ft_count(tmp, 1);
	data->texture.c_color = malloc(sizeof(char *) * (i + 2));
	if (!data->texture.c_color)
		the_ultimate_free(data);
	fill_tab(tmp, data->texture.c_color);
	free_tab(tmp);
	free(temp);
	free(temp2);
}

void	get_color_f(t_cub3D *data, char *line)
{
	char	*temp;
	char	*temp2;
	char	**tmp;
	int		i;

	temp = ft_strtrim(line, "\n");
	temp2 = ft_strtrim(temp, " ");
	free(temp);
	temp = ft_strtrim(temp2, "\t");
	free(temp2);
	temp2 = ft_strtrim(temp, "F");
	tmp = ft_split(temp2, ',');
	i = ft_count(tmp, 1);
	data->texture.f_color = malloc(sizeof(char *) * (i + 1));
	if (!data->texture.f_color)
		the_ultimate_free(data);
	fill_tab(tmp, data->texture.f_color);
	free_tab(tmp);
	free(temp2);
	free(temp);
}

int	get_colors(t_cub3D *data, char *line)
{
	char	**tmp;	
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	tmp = ft_split(line, ' ');
	if (ft_strcmp(tmp[0], "F") == 0)
	{
		free_tab(tmp);
		get_color_f(data, line);
	}
	else if (ft_strcmp(tmp[0], "C") == 0)
	{	
		free_tab(tmp);
		get_color_c(data, line);
	}
	else
		free_tab(tmp);
	return (0);
}
