#include "push_swap.h"

int check_list(t_node **list)
{
		t_node *temp;
		int len;

		len = 0;
		len = len_node(list);
		temp = *list;
		while (len > 1 && temp)
		{
			if (temp->data > temp->next->data)
				return 0;
			temp = temp->next;
			len--;
		}		
		return 1;
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
	if (assembel(argc,argv) == 0)
		return 0;
/*	if (ft_assembel(argc,argv) == 0)
	{
			ft_printf("error\n");
			return 0;
	}
	headref = send_to_a(argc, argv);
	if (check_list(headref) == 0)
		len_list(headref);
	ft_free(headref);*/
	return (0);
}
