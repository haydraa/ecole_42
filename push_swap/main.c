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

void start(int len , char **argv)
{
	t_node **a;

	a = send_to_a(len, argv);
	change(a, len_node(a), len_node(a));
	len_list(a);
	while (len--)
		free(argv[len]);
	ft_free(a);
//	free(argv);
}

int	main(int argc, char **argv)
{
	char *final;
	char **all_final;
	int x;

	x = 0;
	if (argc == 1)
			return 0;
	final = join(argc,argv);
	if (ft_check_arg(final) == 0)
	{
			ft_printf("error\n");
			return 0;
	}
	all_final = ft_split(final, ' ');
	while (all_final[x])
			x++;
	if (to_dob(all_final) == 0)
	{
		ft_printf("error\n");
		return 0;
	}
	start(x,all_final);
	free(all_final);
	free(final);
	return (0);
}
