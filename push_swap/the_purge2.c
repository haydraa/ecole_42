#include "push_swap.h"

void delet_node(t_node **hold,int key)
{
	t_node *temp;
	t_node *prev;
	t_node *del;
	int j;

	j = len_node(hold);
	temp = *hold;
	prev = *hold;
	if (temp->data == key)
	{
		(*hold) = (*hold)->next;
		free(temp);
	}
	else 
	{
		while(prev != NULL)
		{
			if (prev->next->data == key)
			{
				temp = prev->next;
				prev->next = prev->next->next;
				free(temp);
				break;
			}
			else
					prev = prev->next;
		}
	}
}

void change(t_node **a, int i, int x)
{
	t_node *temp;
 	t_node **hold;
 	t_node *temp2;
 	int pos;
	int j;

	x = 0;
 	j = 0;
 	hold = malloc(sizeof(t_node*));
 	*hold = NULL;
	temp = *a;
 	while (temp != NULL)
	{
		pos = temp->data;
		ft_lstadd_back_node(hold,pos);
 		temp = temp->next;
	}
	temp2 = *a;
	while (i > 0)
	{
		temp2 = *a;
 		temp = *hold;
 		pos = find_small(hold,i);
		while(temp && x < pos)
		{
			temp = temp->next;
 			x++;
 		}
 		x = 0;
 		while(temp2->data != temp->data)
				temp2 = temp2->next;
		delet_node(hold,temp->data);
 		temp2->data = j;
 		j++;
 		i--;
	}
	free(hold);
}
