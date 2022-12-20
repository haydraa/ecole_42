#include "fdf.h"

void the_free(t_fdf *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->core_y)
	{
		free(data->tab[i]);
		free(data->repair[i]);
		i++;
	}
	free(data->tab);
	free(data->repair);
}
void change_tab(t_fdf *data ,int index)
{
	int i;
	int j;

	i = 0;
	if (index == 1)
	{
		while (i < data->core_y)
		{
			j = 0;
			while (j < data->core_x)
			{
				if (data->repair[i][j] != 0)
					data->tab[i][j] += 1;
				j++;
			}
			i++;
		}
	}
	else if (index == 0)
	{
		while (i < data->core_y)
		{
			j = 0;
			while (j < data->core_x)
			{
				if (data->repair[i][j] != 0)
					data->tab[i][j] -= 1;
				j++;
			}
			i++;
		}
	}
}
void repair(t_fdf *data)
{
	int i;
	int j;

	j = 0;
	data->repair = (int**)ft_calloc(sizeof(int*), data->core_y);
	while (j < data->core_y)
	{
		data->repair[j] = (int *)ft_calloc(data->core_x, sizeof(int));
		j++;
	}

	i = 0;
	while (i < data->core_y)
	{
		j = 0;
		while (j < data->core_x)
		{
			data->repair[i][j] = data->tab[i][j];
			j++;
		}
		i++;
	}
}
