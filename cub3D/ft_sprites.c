#include "cub3D.h"

t_sprites	*init_struct(t_sprite *sprite, double distance)
{
	t_sprites	*sprites;

	if (!(sprites = (t_sprite *)malloc(sizeof(t_sprites))))
		return(NULL);
	sprites->sprite = sprite;
	sprites->distance = distance;
	sprites->next = NULL;
	sprites->draw_start_x = 0;
	sprites->draw_end_x = 0;
	sprites->draw_start_y = 0;
	sprites->draw_end_y = 0;
	sprites->sprite_x = 0;
	sprites->sprite_y = 0;
	sprites->inv_det = 0;
	sprites->transform_x = 0;
	sprites->transform_y = 0;
	sprites->sprite_screen_x = 0;
	sprites->sprite_height = 0;
	sprites->sprite_width = 0;
	sprites->x = 0;
	sprites->y = 0;
	sprites->text_x = 0;
	sprites->text_y = 0;
	return (sprites);
}

void	sorted_insert(t_sprites **head_ref, t_sprites *new_node)
{
	t_sprites *current;

	if ((*head_ref) == NULL || (*head_ref)->distance <= new_node->distance)
	{
		new_node->next = (*head_ref);
		(*head_ref) = new_node;
	}
	else
	{
		current = (*head_ref);
		while (current->next != NULL && current->next->distance >= new_node->distance)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}

}

void	ft_sprite(t_data *data)
{
	t_sprite	*new;
	t_sprites	*new_sprite;
	t_sprites	*current;
	double		distance;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
			return ; //free  and  exit;
	new->x = data->raycast.map_x;
	new->y = data->raycast.map_y;
	current = data->sprites_head;
	while (current != NULL)
	{
		if (current->sprite->x == new->x && current->sprite->y == new->y)
		{
			free(new);
			return ;
		}
		current = current->next;
	}
	distance = (data->player.pos_x - new->x) * (data->player.pos_y - new->x)
			+ (data->palyer,pos_x - new->x) * (data->palyer.pos_y - new->y);
	new_sprite = init_struct(new, distance);
	sorted_insert(&(data->sprites_head), new_sprite);
}
