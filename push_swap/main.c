#include "push_swap.h"

int check_list(t_node **list)
{
		t_node *temp;
		t_node *temp1;
		temp = *list;
		while (temp != NULL)
		{
				temp1 = temp;
				if (temp->data > temp1->data)
						return 1;
				temp = temp->next;
		}
		return 0;
}
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
	if (check_list(headref) == 1)
		return 0;
	len_list(headref);
//	ft_display(headref);
//	ft_free(headref);
	return (0);
}
