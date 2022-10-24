#include "push_swap.h"

// function to push (add to stack)
void	ft_creat_stack(int value)
{
		t_list *new_node;
		
		new_node = malloc(sizeof(t_list));
		if (new_node == NULL)
				return ;
		new_node->data = value;
}

int	ft_check_arg(char *data)
{
		int i;

		i = 0;
		if (data[0] = '-')
			   i = 1;
		while (data[i])
		{
				if (ft_isdigit(data[i]) == 0)
						return 0;
				i++;
		}
		return 1;
}
// function to pop (remove from stack)
int main(int argc, char **argv)
{

	int i;
	int j;

	j = 0; 
	i = 0;
	while (argc != 0)
	{
			if (ft_check_arg(argv[i]) == 1)
			{
				ft_printf("error");
				return 0;
			}
			i++;
	}
	return (0);
}
