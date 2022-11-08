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
		else if (i > 3)
			casses_over_3(lsit);
}

void	casses_over_3(t_list **node);
{
	t_node *temp;

	temp = *list;

}

void casses_of_2(t_node **list)
{
		t_node *temp;

		temp = *list
		if (temp-data > temp->next->data)
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
					return ;
			}
			else if (temp->data < temp->next->data && (*list)->data > temp->next->data)
			{
					ra(list);
					return;
			}
			else if (temp->data < temp->next->data)
			{
					sa(list);
					return ;
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

