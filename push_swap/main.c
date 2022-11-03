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
		new_node->next = head;
		head = new_node;
		ft_display(head);
		return head;
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
		sawp_a(&top);
		//ft_display(top);
}

void send_to_stack(char **args)
{
		int i;
		i = 1;
		while (args[i])
		{
			in_stack_a(ft_atoi(args[i]));
			i++;
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
	send_to_stack(argv);
	return (0);
}
