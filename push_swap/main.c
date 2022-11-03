#include "push_swap.h"

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

void ft_display(t_node *top)
{
		t_node	*temp;
		temp = top;
		while (temp != NULL)
		{
				ft_printf("%d\n", temp->data);
				temp = temp->next;
		}
		free(temp);
}

void send_to_stack(int argc, char **args)
{
		t_node 	*head;
		t_node 	*new;
		int i;
		
		i = 1;
		head = NULL;
		while (i < argc)
		{
			new = in_stack_a(ft_atoi(args[i]));
			ft_lstadd_back_node(&head, new);
			i++;
		}
		ft_display(head);
		sawp_a(&head);
		ft_display(head);
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

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 2;
	if (ft_assembel(argc,argv) == 0)
	{
			ft_printf("error\n");
			return 0;
	}
	send_to_stack(argc, argv);
	return (0);
}
