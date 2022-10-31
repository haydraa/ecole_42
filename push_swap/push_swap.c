#include "push_swap.h"

void	*ft_creat_stack(int value)
{
		t_node *new_node;
		
		new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
				return NULL;
		new_node->data = value;

}

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 2;
	ft_assembel(argc,argv);
	return (0);
}

