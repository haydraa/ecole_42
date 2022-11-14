/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghribi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:42:01 by jghribi           #+#    #+#             */
/*   Updated: 2022/11/11 15:31:15 by jghribi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void len_list(t_node **list)
{
		t_node *temp;
		int i;

		i = 0;
		temp = *list;
		while (temp != NULL)
		{
			temp = temp->next;
			i++;
		}
		if (i == 1)
				return ;
		else if (i == 2)
			casses_of_2(list);
		else if (i == 3)
				casses_of_3(list);
		else if (i > 3 && i < 6)
			casses_over_3(list , i);
}

void	casses_over_3(t_node **list, int i)
{	
	t_node **b;
	t_node	*new;
	t_node *temp;
	t_node *temp_a;
	int 	pos;

	pos = 0;
   	temp = *b;
	temp_a = *list;
	b = malloc(sizeof(t_node *));
	*b = NULL;
	while (i > 3)
	{
		new = pb(list);
		ft_lstadd_front_node(b,new);
		i--;
	}
	len_list(list);
	while (temp != NULL)
	{
		pos = check_pos(list, *b);
		if (pos == len_node(list))
		{
			pa(list,b);
			ra(list);
		}
		else 
		{
			pa(list,b);	
			/*new = temp;
			new->next = NULL;
			while (pos--)
					temp_a = temp_a->next;	
			temp_a->next = new;
			new->next = temp_a->next;*/
		}
		temp = temp->next;
	}
	ft_display(list);
}

void casses_of_2(t_node **list)
{
		t_node *temp;

		temp = *list;
		if (temp->data > temp->next->data)
		{
				sa(list);
				return ;
		}
}

void casses_of_3(t_node **list)
{
	t_node *temp;

	temp = *list;
	if (temp->data > temp->next->data)	
	{
		temp = temp->next;
		if(temp->data > temp->next->data)
		{
				sa(list);
				rra(list);
		}
		else if (temp->data < temp->next->data && (*list)->data > temp->next->data)
		{
				ra(list);
		}
		else if (temp->data < temp->next->data)
		{
				sa(list);
		}
	}
	else 
		(casses_of_3v2(list));
}

void casses_of_3v2(t_node **list)
{
	t_node *temp;
	
	temp = *list;
	if (temp->data < temp->next->data)
	{
			temp = temp->next;
			if (temp->data > temp->next->data && temp->next->data > (*list)->data)
			{
					sa(list);
					ra(list);
					return ;
			}
			if (temp->next->data < (*list)->data && temp->next->data < (*list)->data)
			{
					rra(list);
					return ;
			}
	}
}

