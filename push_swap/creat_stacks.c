#include "push_swap.h"

void	ft_lstadd_front_node(t_node **list, t_node *new)
{
	if (!new)
		return ;
	new->next = new;
	new->next = (*list);
	(*list) = new;
}

t_node	*in_stack_a(int value)
{
		t_node *head;
		t_node *new_node;

		head = NULL;
		new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
			return (NULL);
		new_node->data = value;
		new_node->next = NULL;	
		return (new_node);
}

t_node **send_to_a(int argc, char **args)
{
		t_node 	**head;
		t_node 	*new;
		int i;
		
		i = 0;
		head = malloc(sizeof(t_node*));
		*head = NULL;
		while (i < argc)
		{
			new = in_stack_a(ft_atoi(args[i]));
			ft_lstadd_back_node(head, new);
			i++;
		}
		return (head);
}

void	ft_lstadd_back_node(t_node **lst, t_node *new)
{
	t_node	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp && temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

