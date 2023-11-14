#include "cub3D.h"

int	texture_id(t_cub3D *data, char *line)
{
	char	**tmp;
	char	*trim;
	int		i;

	i = 0;
	trim = ft_strtrim(line, "\t");
	while (trim[i++])
	{
		if (trim[i] == '\t')
			trim[i] = ' ';
	}
	tmp = ft_split(trim, ' ');
	if (identifcation(data, tmp) == 0)
	{
		free(trim);
		data->texture.index++;
		free_tab(tmp);
		return (0);
	}
	else
	{
		free(trim);
		free_tab(tmp);
		return (1);
	}
}

int	check_map_in_map(t_cub3D *data, char *line, int *j, int *i)
{
	data->map.map_space = *i;
	if (line[(*j) - 1] != '1')
		return (-1);
	while (line[(*j)])
	{
		if (line[(*j)] == '1')
			break ;
		else if (line[(*j)] != ' ' && line[(*j)] != '1')
			return (-1);
		else
			(*i)++;
		(*j)++;
	}
	data->map.index++;
	return (0);
}

int	line_check_norm(t_cub3D *data, char *temp, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (temp[j])
	{
		if (temp[j] == ' ' && data->map.map != NULL)
			if (check_map_in_map(data, temp, &j, &i) == -1)
				break ;
		if ((temp[j] == '1' || temp[j] == '0'
				||temp[j] == '2' || temp[j] == 'N'
				|| temp[j] == 'S' || temp[i] == 'E'
				|| temp[i] == 'W' || temp[i] == ' '))
			i++;
		j++;
	}
	if (len == i && len != 0)
	{
		data->map.tmp = ft_strdup(temp);
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

int	line_check_utils(t_cub3D *data, char *temp2)
{
	char	*temp;
	int		len;

	temp = ft_strtrim(temp2, " ");
	free(temp2);
	len = ft_strlen(temp);
	return (line_check_norm(data, temp, len));
}

int	line_check(char *line, t_cub3D *data)
{
	char	*temp2;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (ft_strlen(line) < 2)
		return (1);
	temp2 = ft_strdup(line);
	while (temp2[i] && temp2[i] != '1')
	{
		if (temp2[i] == '\t' || temp2[i] == ' ')
			temp2[i] = '1';
		i++;
	}
	while (temp2[i])
	{
		if (temp2[i] == '\t' || temp2[i] == '\n')
			temp2[i] = ' ';
		i++;
	}
	return (line_check_utils(data, temp2));
}
