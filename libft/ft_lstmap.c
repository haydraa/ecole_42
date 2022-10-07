#include "libft.h"

/*t_list *ft_lstmap(t_list *lst, void *(*f)(void *),  void *(del)(void*))
{
	t_list *new;
	new = malloc(sizeof(lst));
	if (new == NULL)
		return NULL;
	if (lst == NULL)
		return NULL;
	while (lst)
		new = ft_lstiter(lst,(*f)(void *));
	if (del != NULL)
		new = ft_lstdelone(lst, (del)(void*));
	return new;
}*/
