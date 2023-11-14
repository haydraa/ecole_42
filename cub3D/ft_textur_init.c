#include "cub3D.h"

t_image	*image_init(void)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img_data = NULL;
	image->img_ptr = NULL;
	image->path = NULL;
	image->bpp = 0;
	image->endian = 0;
	image->size_line = 0;
	image->width = 0;
	image->height = 0;
	return (image);
}

void	free_and_exit(t_cub3D *data)
{
	free_image(data, data->north);
	free_image(data, data->south);
	free_image(data, data->west);
	free_image(data, data->east);
	free_image(data, data->image);
	free(data->player);
	mlx_destroy_display(data->mlx.mlx_ptr);
	free(data->mlx.mlx_ptr);
	the_ultimate_free(data);
}

void	set_texture(t_cub3D *data, t_image *image)
{
	image->img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			image->path, &image->width, &image->height);
	if (image->img_ptr == NULL)
	{
		printf("ERROR: FAILL TO LOAD TEXTURE: %s\n", image->path);
		free_and_exit(data);
	}
	image->img_data = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->size_line), &(image->endian));
}

void	fill_texturs(t_cub3D *data)
{
	set_texture(data, data->north);
	set_texture(data, data->south);
	set_texture(data, data->west);
	set_texture(data, data->east);
}

void	texture_init(t_cub3D *data)
{
	data->north = image_init();
	if (!data->north)
		the_ultimate_free(data);
	data->north->path = ft_strtrim(data->texture.north, "\n");
	data->south = image_init();
	if (!data->south)
		the_ultimate_free(data);
	data->south->path = ft_strtrim(data->texture.south, "\n");
	data->west = image_init();
	if (!data->west)
		the_ultimate_free(data);
	data->west->path = ft_strtrim(data->texture.west, "\n");
	data->east = image_init();
	if (!data->east)
		the_ultimate_free(data);
	data->east->path = ft_strtrim(data->texture.east, "\n");
	data->image = image_init();
	if (!data->image)
		the_ultimate_free(data);
}
