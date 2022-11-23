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
		while (temp)
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
	t_node **headref;
	char *final;
	char **all_final;
	
	i = 0;
	final = join(argc,argv);
//	ft_printf("%s\n", final);
	if (ft_check_arg(final) == 0)
	{
			ft_printf("error\n");
			return 0;
	}
	all_final = ft_split(final, ' ');
	while(all_final[i])
		i++;
	headref = send_to_a(i, all_final);
	//change(headref,len_node(headref), len_node(headref));
	len_list(headref);
	ft_free(headref);
	free(all_final);
	free(final);
	return (0);
}
