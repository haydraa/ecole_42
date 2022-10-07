#include "libft.h"

void ft_lstadd_back(t_list **lst,t_list *new)
{
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	else
	{	
		*lst = ft_lstlast(*lst);
	}
	(*lst)->next = new;

}
