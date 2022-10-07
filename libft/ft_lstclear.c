
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return;
	while (*lst != NULL)
	{
		del((*lst)-> next);
		free(lst);
	}
}
