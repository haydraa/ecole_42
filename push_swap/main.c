#include "push_swap.h"

void ft_display(t_node **top)
{
		t_node	*temp;
		temp = *top;
		while (temp != NULL)
		{
				ft_printf("%d\n", temp->data);
				temp = temp->next;
		}
}

void ft_free(t_node **list)
{
	t_node *corrent;
	t_node *next;

	corrent = *list;
	while (corrent != NULL)
	{
			next = corrent->next;
			free(corrent);
			corrent = next;
	}
	*list = NULL;
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	t_node **headref;
	
	i = 1;
	j = 2;
	if (ft_assembel(argc,argv) == 0)
	{
			ft_printf("error\n");
			return 0;
	}

	headref = send_to_a(argc, argv);
	ft_display(headref);
	casses_of_3(headref);
	ft_display(headref);
//	ft_free(headref);
	return (0);
}
