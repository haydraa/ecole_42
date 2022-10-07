#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *the_new_node;
	the_new_node = malloc(sizeof(*the_new_node));
	if (the_new_node == NULL)
		return NULL;
	the_new_node -> content = content;
	return (the_new_node);
}
