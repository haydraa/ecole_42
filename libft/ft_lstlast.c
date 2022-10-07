#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return lst;
	if (lst->next == NULL)
		return (lst);
	return (ft_lstlast(lst->next));
}
