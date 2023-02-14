#include "push_swap.h"

int	give_num(t_node **a, int pos)
{
	t_node	*temp;
	int		len;

	len = len_node(a);
	temp = *a;
	while (pos)
	{
		temp = temp->next;
		pos--;
	}
	if (temp == NULL)
		return (-1);
	return (temp->data);
}

void	checker(t_node **a, t_node **b, t_node *temp)
{
	int	len;

	len = len_node(b);
	if ((*b) == NULL)
	{
		pb(a, b);
		return ;
	}
	if (temp->data >= (*b)->data)
		rb(b);
	pb(a, b);
}

void	ft_free(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

void	min_max(t_node **a, t_node **b, t_data *data)
{
	int		hold_first;
	int		len;
	int		nood_num;
	t_node	*temp;

	if ((*a) == NULL)
		return ;
	len = len_node(a);
	hold_first = find_first(a, data->p_min, data->p_max);
	data->index = 0;
	nood_num = give_num(a, hold_first);
	if (nood_num == -1)
		return ;
	while ((*a)->data != nood_num)
		ra(a);
	temp = *a;
	checker(a, b, temp);
}
