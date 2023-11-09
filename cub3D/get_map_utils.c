#include "cub3D.h"

void	cub_free(t_cub3D *data)
{
	the_ultimate_free(data);
}

void	free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
			free(tab[i]);
	free(tab);
}

int	count_y(char **argv, t_cub3D *data)
{
	int y;
	int fd;
	char *line;

	y = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line_check(line, data) == 0)
			break;
		free(line);
	}
	y++;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		y++;
	}
	close(fd);
	free(line);
	return (y);
}
	
int	texture_id(t_cub3D *data, char *line)
{
	char **tmp;
	char *trim;
	int i = 0;

	trim = ft_strtrim(line, "\t");
	while (trim[i])
	{
		if (trim[i] == '\t')
			trim[i] = ' ';
		i++;
	}
	tmp = ft_split(trim, ' ');
	if (ft_strcmp(tmp[0], "NO") == 0)
		data->texture.north = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "SO") == 0)
		data->texture.south = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "WE") == 0)
		data->texture.west = ft_strdup(tmp[1]);
	else if (ft_strcmp(tmp[0], "EA") == 0)
		data->texture.east = ft_strdup(tmp[1]);
	else
	{
		free(trim);
		free_tab(tmp);
		return (1);	
	}
	free(trim);
	data->texture.index++;
	free_tab(tmp);
	return (0);
}

int ft_count(char **tmp, int x)
{
	int i;
	i = 0;

	while (tmp[i])
		i++;
	if ((i <= 3 || i > 4) && x != 1)
		return (-1);
	return (i);
}

bool stupid_check(char *str)
{
	int i;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (i == ft_strlen(str))
		return (true);
	return (false);

}

void	get_color_F(t_cub3D *data, char *line)
{
	char *temp;
	char *temp2;
	char **tmp;
	int i;

	temp = ft_strtrim(line ,"\n");
	temp2 = ft_strtrim(temp, " ");
	free(temp);
	temp = ft_strtrim(temp2, "\t");
	free(temp2);
	temp2 = ft_strtrim(temp, "F");
	tmp = ft_split(temp2, ',');
	i = ft_count(tmp, 1);
	if (!(data->texture.f_color = malloc(sizeof(char *) * (i + 1))))
		the_ultimate_free(data);
	i = -1;
	while (tmp[++i])
	{
		if (stupid_check(tmp[i]))
			data->texture.f_color[i] = ft_strdup("");	
		else
			data->texture.f_color[i] = ft_strtrim(tmp[i], " ");	
				
	}
	data->texture.f_color[i] = NULL;
	free_tab(tmp);
	free(temp2);
	free(temp);	
}

void	get_color_C(t_cub3D *data, char *line)
{
	char *temp;
	char *temp2;
	char **tmp;
	int i;

	temp = ft_strtrim(line ,"\n");
	temp2 = ft_strtrim(temp, " ");
	free(temp);
	temp = ft_strtrim(temp2, "\t");
	free(temp2);
	temp2 = ft_strtrim(temp, "C");
	tmp = ft_split(temp2, ',');
	i = ft_count(tmp, 1);
	if (!(data->texture.c_color = malloc(sizeof(char *) * (i + 2))))
		the_ultimate_free(data);
	i = -1;
	while (tmp[++i])
	{
		if (stupid_check(tmp[i]))
			data->texture.c_color[i] = ft_strdup("");	
		else
			data->texture.c_color[i] = ft_strtrim(tmp[i], " ");				
	}
	data->texture.c_color[i--] = NULL;
	free_tab(tmp);
	free(temp);
	free(temp2);
}

int	get_colors(t_cub3D *data, char *line)
{
	char **tmp;	

	tmp = ft_split(line, ' ');
	if (ft_strcmp(tmp[0], "F") == 0)
	{
		free_tab(tmp);
		get_color_F(data,line);
	}
	else if (ft_strcmp(tmp[0], "C") == 0)
	{	
		free_tab(tmp);
		get_color_C(data,line);
	}
	else
		free_tab(tmp);
	return (0);
}

int line_check(char *line, t_cub3D *data)
{
	char *temp;
	char *temp2;
	int i;
	int j;
	int len;

	j = 0; 
	i = 0;
	if (ft_strlen(line) < 2)
		return (1);
	temp2 = ft_strdup(line);
	while (temp2[i])
	{
		if (temp2[i] == '\t' || temp2[i] == '\n')
			temp2[i] = ' ';
		i++;
	}
	temp = ft_strtrim(temp2, " ");
	free(temp2);
	len = ft_strlen(temp);
	i = 0;
	while (temp[j])
	{
		if ((temp[j] == '1'||temp[j] == '0'
		||temp[j] == '2' || temp[j] == 'N' 
		|| temp[j] == 'S' || temp[i] == 'E' 
		|| temp[i] == 'W'))
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
