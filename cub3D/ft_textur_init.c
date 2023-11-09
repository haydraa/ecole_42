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

void	set_texture(t_cub3D *data, t_image *image)
{
	image->img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr, image->path,	&image->width, &image->height);
	if (image->img_ptr == NULL)
	{
		printf("ERROR: FAILL TO LOAD TEXTURE .....\n");
		//free;
		exit(1);
	}
	image->img_data =	mlx_get_data_addr(image->img_ptr, &(image->bpp), &(image->size_line), &(image->endian));
}

void	fill_texturs(t_cub3D *data)
{
	set_texture(data, data->north);
	set_texture(data, data->south);
	set_texture(data, data->west);
	set_texture(data, data->east);
	//sp_if needed;
}

void	texture_init(t_cub3D *data)
{
	//find more attractive way to exit if malloc faile;
	if(!(data->north = image_init()))
		exit(1);
	data->north->path = ft_strtrim(data->texture.north, "\n");
	if(!(data->south = image_init()))
		exit(1);
	data->south->path = ft_strtrim(data->texture.south, "\n");
	if(!(data->west = image_init()))
		exit(1);
	data->west->path = ft_strtrim(data->texture.west, "\n");
	if(!(data->east = image_init()))
		exit(1);
	data->east->path = ft_strtrim(data->texture.east, "\n");
	if (!(data->image = image_init()))
		exit(1);
}
