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
	char *path;
	
	path = ft_strtrim(image->path, "\n");
		int i = open(path, O_RDONLY);
		printf("%d  %s\n", i, image->path);
	image->img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr, path,
			&image->width, &image->height);
	if (image->img_ptr == NULL)
	{
			printf("LOAD FAILL TEXTURE .....\n");
		//free;
		exit(1);
	}
	mlx_get_data_addr(image->img_ptr, &(image->bpp), &(image->size_line),
					&(image->endian));
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
	int i;

	i = 0;
	if(!(data->north = image_init()))
		exit(1);
	data->north ->path = data->texture.north;
	if(!(data->south = image_init()))
		exit(1);
	data->south->path = data->texture.south;
	if(!(data->west = image_init()))
		exit(1);
	data->west->path = data->texture.west;
	if(!(data->east = image_init()))
		exit(1);
	data->east->path = data->texture.east;
	if (!(data->image = image_init()))
		exit(1);
	if (i == 1)
	{
		printf("Error_malloc_init_image");
		//free; dont forget;
		exit(1);
	}
//	fill_texturs(data);
}
