#include "push_swap.h"

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
