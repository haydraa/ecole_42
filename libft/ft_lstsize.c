#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int  i;
	i = 0;
	if (lst == NULL)
		return i;
	while(lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
