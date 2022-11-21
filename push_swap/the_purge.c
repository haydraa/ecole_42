#include "push_swap.h"

int	find_small(t_node **list, int i)
{
	t_node	*temp;
	t_node	*small;
	int		len;
	int		x;

	x = 0;
	len = i;
	temp = *list;
	small = *list;
	while (len > 0)
	{
		if (small->data > temp->data)
		{
			small = temp;
		}
		temp = temp->next;
		len--;
 	}
	temp = *list;
 	while (temp->data != small->data)
	{
		x++;
		temp = temp->next;
	}
	return x;
}

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
 		temp2 = in_stack_a(pos);
		ft_lstadd_back_node(hold,temp2);
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
}

int	find_first_back(t_node **a ,int min ,int max)
{
	t_node *current;
	t_node *prev;
	t_node *next;
	t_node *temp;
	int pos;

	pos = 0;
	current = *a;
	next = NULL;
	while(current != NULL)
	{   
		next = current->next;
		current->next = prev;
 		prev = current;
 		current = next;
 	}
	*a = prev;
	temp = *a;
	while (temp)
	{
		if (temp->data <= min || temp->data > max)
			break;
		else 
		{
				temp = temp->next;
				pos++;
		}
	}
	unreverse(a);
//	ft_display(a);
	return 1;
}

int	find_first(t_node **a, int min, int max)
{
	t_node	*temp;
	t_node	*hold;
	t_node  *rev;
	int	pos;

	pos = 0;
	temp = *a;
	while (temp != NULL)
	{
		if (temp->data >= min && temp->data > max)
				break;
		else
		{
			temp = temp->next;
			pos++;
		}
	}
	return pos;	
}
